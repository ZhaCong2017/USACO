/*
ID:chac161
TASK:sprime
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

ifstream fin("sprime.in");
ofstream fout("sprime.out");
int n;
int num[6] = { 1, 2, 3, 5, 7, 9 };

bool isprime(int n)
{
	if (n == 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

void dfs(int x, int position)
{
	if (position == n)
	{
		fout << x << endl;
		return;
	}
	for (int i = 0; i < 6; i++)
	{
		if (isprime(x * 10 + num[i]))
			dfs(x * 10 + num[i], position + 1);
	}
}

int main()
{
	fin >> n;
	for (int i = 0; i < 6; i++)
	{
		if (isprime(num[i]))
			dfs(num[i], 1);
	}

	//system("pause");
	return 0;
}
