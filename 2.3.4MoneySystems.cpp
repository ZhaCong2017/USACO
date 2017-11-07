/*
ID:chac161
TASK:money
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<set>
using namespace std;
long long t[10010];

int main()
{
	ifstream fin("money.in");
	ofstream fout("money.out");
	int v, n;
	fin >> v >> n;
	int *num = new int[v];
	for (int i = 0; i < v; i++)
		fin >> num[i];

	t[0] = 1;
	for (int i = 0; i < v; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j >= num[i])
			{
				t[j] += t[j - num[i]];
			}
		}
	}
	fout << t[n] << endl;

	//system("pasue");
	return 0;
}
