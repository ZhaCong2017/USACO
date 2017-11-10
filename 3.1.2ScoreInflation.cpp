/*
ID:chac161
TASK:inflate
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int dp[10005];

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	ifstream fin("inflate.in");
	ofstream fout("inflate.out");
	int m, n;
	fin >> m >> n;
	int *point = new int[n + 5];
	int *minute = new int[n + 5];
	for (int i = 1; i <= n; i++)
		fin >> point[i] >> minute[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = minute[i]; j <= m; j++)
		{
			dp[j] = max(dp[j], dp[j - minute[i]] + point[i]);
		}
	}
	fout << dp[m] << endl;

	//system("pasue");
	return 0;
}
