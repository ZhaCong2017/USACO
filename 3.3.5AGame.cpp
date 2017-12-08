/*
ID:chac161
TASK:game1
LANG:C++
*/

#include <iostream>
#include<fstream>
using namespace std;
int n;
int data[105];
int sum[105];
int dp[105][105];

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	ifstream fin("game1.in");
	ofstream fout("game1.out");
	fin >> n;
	for (int i = 1; i <= n; i++)
	{
		fin >> data[i];
		sum[i] = sum[i - 1] + data[i];
		dp[i][i] = data[i];
	}

	for (int i = n; i >= 1; i--)
	{
		for (int j = i + 1; j <= n; j++)
		{
			dp[i][j] = max(sum[j] - sum[i] - dp[i + 1][j] + data[i], sum[j - 1] - sum[i - 1] - dp[i][j - 1] + data[j]);
		}
	}
	fout << dp[1][n] << " " << sum[n] - dp[1][n] << endl;
	//system("pause");
	return 0;
}
