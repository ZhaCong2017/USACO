/*
ID:chac161
TASK:transform
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<map>
using namespace std;

ifstream fin("transform.in");
ofstream fout("transform.out");

char **create(int n)
{
	char **tmp = new char*[n];
	for (int i = 0; i < n; i++)
		tmp[i] = new char[n];
	return tmp;
}

void input(char **x, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			fin >> x[i][j];
}

bool same(char ** a, char **b, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != b[i][j])
				return false;
	return true;
}

char **r90(char **start, int n)
{
	char **end = create(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			end[j][n - 1 - i] = start[i][j];
	return end;
}

char **r180(char **start, int n)
{
	char **tmp = r90(start, n);
	return r90(tmp, n);
}

char **r270(char **start, int n)
{
	char **tmp = r180(start, n);
	return r90(tmp, n);
}

char **reflection(char **start, int n)
{
	char **end = create(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			end[i][n - 1 - j] = start[i][j];
	}
	return end;
}

int main()
{
	int n;
	fin >> n;
	char **start = create(n);
	char **end = create(n);
	char **tmp;
	input(start, n);
	input(end, n);
	for (int i = 1; i < 8; i++)
	{
		switch (i)
		{
		case 1:
			tmp = r90(start, n);
			break;
		case 2:
			tmp = r180(start, n);
			break;
		case 3:
			tmp = r270(start, n);
			break;
		case 4:
		case 5:
			tmp = reflection(start, n);
			break;
		default:
			tmp = start;
			break;
		}
		if (i == 7)
			fout << i << endl;
		else if (i == 5)
		{
			for (int j = 0; j < 3; j++)
			{
				tmp = r90(tmp, n);
				if (same(tmp, end, n))
				{
					fout << i << endl;
					return 0;
				}
			}
		}
		else if (same(tmp, end, n))
		{
			fout << i << endl;
			break;
		}
	}
	//system("pause");
	return 0;
}
