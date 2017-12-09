/*
ID:chac161
TASK:nuggets
LANG:C++
*/

#include <iostream>
#include<fstream>
using namespace std;
int num[12];
bool have[70000];

int gcd(int a, int b)
{
	return a == 0 ? b : gcd(b % a, a);
}

int main()
{
	ifstream fin("nuggets.in");
	ofstream fout("nuggets.out");
	int n;
	fin >> n;
	for (int i = 0; i < n; i++)
		fin >> num[i];
	int max = 70000;
	have[0] = true;
	int g = num[0];
	for (int i = 1; i < n; i++)
	{
		g = gcd(g, num[i]);
		if (g == 1)
			break;
	}
	if (g != 1)
	{
		fout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		have[num[i]] = true;
		if (num[i] == 1)
		{
			fout << 0 << endl;
			return 0;
		}
		for (int j = num[i]; j < max; j++)
		{
			if (have[j - num[i]])
				have[j] = true;
		}
	}

	for (int i = max - 1; i >= 0; i--)
	{
		if (have[i] == false)
		{
			fout << i << endl;
			break;
		}
	}
	//system("pause");
	return 0;
}
