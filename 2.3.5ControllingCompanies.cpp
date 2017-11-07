/*
ID:chac161
TASK:concom
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<set>
#include<map>
using namespace std;
#define MAX 102

int connection[105][105];
int owner[105][105];

int main()
{
	ifstream fin("concom.in");
	ofstream fout("concom.out");
	int n;
	fin >> n;
	int a, b, c;
	for (int i = 0; i < MAX; i++)
		owner[i][i] = 1;
	for (int i = 0; i < n; i++)
	{
		fin >> a >> b >> c;
		connection[a][b] = c;
		if (c > 50)
			owner[a][b] = 1;
	}

	for (int t = 0; t < MAX; t++)
	{
		for (int i = 1; i <= MAX; i++)
		{
			for (int j = 1; j <= MAX; j++)
			{
				if (owner[i][j] == 1)
				{
					continue;
				}
				int tmp = 0;
				for (int k = 1; k <= MAX; k++)
				{
					if (owner[i][k] == 1)
						tmp += connection[k][j];
				}
				if (tmp > 50)
					owner[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= MAX; i++)
	{
		for (int j = 1; j <= MAX; j++)
		{
			if (i != j && owner[i][j] == 1)
				fout << i << ' ' << j << endl;
		}
	}
	//system("pasue");
	return 0;
}
