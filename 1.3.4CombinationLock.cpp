/*
ID:chac161
TASK:combo
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<map>
using namespace std;
int n;
map<int, int> password;

int findx(int x)
{
	while (x <= 0)
		x += n;
	while (x > n)
		x -= n;
	return x;
}

void findnum(int *a)
{
	int num[3][5];
	int tmp;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
			num[i][j] = findx(a[i] + j - 2);
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				tmp = num[0][i] * 10000 + num[1][j] * 100 + num[2][k];
				password[tmp] = 1;
			}
		}
	}
}

int main()
{
	ifstream fin("combo.in");
	ofstream fout("combo.out");
	int a[3], b[3];
	fin >> n;
	for (int i = 0; i < 3; i++)
		fin >> a[i];
	for (int j = 0; j < 3; j++)
		fin >> b[j];

	findnum(a);
	findnum(b);
	fout << password.size() << endl;

	//system("pause");
	return 0;
}
