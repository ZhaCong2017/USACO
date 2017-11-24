/*
ID:chac161
TASK:shopping
LANG:C++
*/

#include <iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int price[6], need[6];
int pack[100], discount[100], disitem[100][6], disnum[100][6], dislist[100][6];
int dp[6][6][6][6][6];

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	ifstream fin("shopping.in");
	ofstream fout("shopping.out");
	int n, m, num, c, k, p;
	map<int, int> mapping;

	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> pack[i];
		for (int j = 1; j <= pack[i]; j++)
		{
			fin >> disitem[i][j] >> disnum[i][j];
		}
		fin >> discount[i];
	}
	fin >> m;
	for (int i = 1; i <= m; i++)
	{
		fin >> c >> k >> p;
		need[i] = k;
		price[i] = p;
		mapping[c] = i;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= pack[i]; j++)
			dislist[i][mapping[disitem[i][j]]] = disnum[i][j];
	}

	for (int i1 = 0; i1 < 6; i1++)
	for (int i2 = 0; i2 < 6; i2++)
	for (int i3 = 0; i3 < 6; i3++)
	for (int i4 = 0; i4 < 6; i4++)
	for (int i5 = 0; i5 < 6; i5++)
	{
		dp[i1][i2][i3][i4][i5] = i1 * price[1] + i2 * price[2] + i3 * price[3] + i4 * price[4] + i5 * price[5];
		for (int i = 0; i < n; i++)
		{
			int tmp;
			if (i1 >= dislist[i][1] && i2 >= dislist[i][2] && i3 >= dislist[i][3] && i4 >= dislist[i][4] && i5 >= dislist[i][5])
			{
				tmp = discount[i] + dp[i1 - dislist[i][1]][i2 - dislist[i][2]][i3 - dislist[i][3]][i4 - dislist[i][4]][i5 - dislist[i][5]];
				dp[i1][i2][i3][i4][i5] = min(dp[i1][i2][i3][i4][i5], tmp);
			}
		}
	}

	fout << dp[need[1]][need[2]][need[3]][need[4]][need[5]] << endl;
	//system("pause");
	return 0;
}
