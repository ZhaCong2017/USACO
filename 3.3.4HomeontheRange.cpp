/*
ID:chac161
TASK:range
LANG:C++
*/

#include <iostream>
#include<fstream>
#include<string>
using namespace std;
int n;
int map[255][255];
int dp[255][255];
int result[255];

int min(int a, int b, int c)
{
	int result = a < b ? a : b;
	return result < c ? result : c;
}

int main()
{
	ifstream fin("range.in");
	ofstream fout("range.out");
	fin >> n;
	string tmp;
	for (int i = 0; i < n; i++)
	{
		fin >> tmp;
		for (int j = 0; j < n; j++)
			map[i][j] = tmp[j] - '0';
	}

	for (int i = 0; i < n; i++)
	{
		if (map[i][0])
			dp[i][0] = 1;
		if (map[0][i])
			dp[0][i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (map[i][j] == 0)
				dp[i][j] = 0;
			else
				dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			while (dp[i][j] >= 2)
			{
				result[dp[i][j]]++;
				dp[i][j]--;
			}
		}
	}
	
	for (int i = 2; i <= n; i++)
	{
		if (result[i] != 0)
			fout << i << ' ' << result[i] << endl;
	}
	//system("pause");
	return 0;
}
