/*
ID:chac161
TASK:subset
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<map>
using namespace std;

int main()
{
	ifstream fin("subset.in");
	ofstream fout("subset.out");
	int n;
	fin >> n;
	long long  *dp = new long long[n * (n + 1) / 2 + 5]();
	if (n * (n + 1) / 2 % 2 != 0)
	{
		fout << 0 << endl;
		return 0;
	}
	dp[0] = 1;
	int max = n * (n + 1) / 2;
	for (int i = 1; i <= n; i++)
	{
		for (int j = max; j >= i; j--)
		{
			dp[j] += dp[j - i];
		}
	}
	fout << dp[n * (n + 1) / 4] / 2 << endl;
	//system("pasue");
	return 0;
}
