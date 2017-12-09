/*
ID:chac161
TASK:rockers
LANG:C++
*/

#include <iostream>
#include<fstream>
using namespace std;
int data[25];
int dp[25][25][25];

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	ifstream fin("rockers.in");
	ofstream fout("rockers.out");
	int n, t, m;
	fin >> n >> t >> m;

	for (int i = 1; i <= n; i++)
		fin >> data[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 0; k <= t; k++)
			{
				dp[i][j][k] = dp[i - 1][j][k];
				if (data[i] <= t)
				{
					if (k >= data[i])
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - data[i]] + 1);				
					if (j > 1)
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][t - data[i]] + 1);
				}
			}
		}
	}
	
	fout << dp[n][m][t] << endl;

	//system("pause");
	return 0;
}
