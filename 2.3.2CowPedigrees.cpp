/*
ID:chac161
TASK:nocows
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<queue>
#include<set>
using namespace std;
#define MOD 9901
int dp[105][205];

int main()
{
	ifstream fin("nocows.in");
	ofstream fout("nocows.out");
	int n, k;
	fin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		dp[i][1] = 1;
		for (int j = 1; j <= n; j += 2)
		{
			for (int l = 1; l <= j - 2; l += 2)
				dp[i][j] = (dp[i][j] + dp[i - 1][j - l - 1] * dp[i - 1][l]) % MOD;

		}
	}
	if (dp[k][n] >= dp[k - 1][n])
		fout << dp[k][n] - dp[k - 1][n] << endl;
	else
		fout << dp[k][n] + MOD - dp[k - 1][n] << endl;
	//system("pasue");
	return 0;
}
