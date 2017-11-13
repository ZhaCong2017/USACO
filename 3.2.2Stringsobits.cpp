/*
ID:chac161
TASK:kimbits
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
int dp[40][40];

int main()
{
	ifstream fin("kimbits.in");
	ofstream fout("kimbits.out");
	long long n, L, I;
	fin >> n >> L >> I;
	for (int i = 0; i < 40; i++)
		dp[i][0] = dp[0][i] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
	}

	for (int i = n; i >= 1; i--)
	{
		if (dp[i - 1][L] >= I)
			fout << '0';
		else
		{
			fout << '1';
			I -= dp[i - 1][L];
			L--;
		}
	}
	fout << endl;
	//system("pasue");
	return 0;
}
