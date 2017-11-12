/*
ID:chac161
TASK:stamps
LANG:C++
*/

#include<iostream>
#include<fstream>
using namespace std;
int num[2000000];

int main()
{
	ifstream fin("stamps.in");
	ofstream fout("stamps.out");
	int k, n, result;
	fin >> k >> n;
	int *value = new int[n];
	for (int i = 0; i < 2000000; i++)
		num[i] = 10000000;
	for (int i = 0; i < n; i++)
		fin >> value[i];
	num[0] = 0;
	for (int i = 1; ; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i - value[j] >= 0 && k >= num[i - value[j]] + 1 && num[i] > num[i - value[j]] + 1)
				num[i] = num[i - value[j]] + 1;
		}
		if (num[i] == 10000000)
		{
			result = i;
			break;
		}
	}
	fout << result - 1 << endl;
	//system("pasue");
	return 0;
}
