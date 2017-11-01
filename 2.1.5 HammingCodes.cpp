/*
ID:chac161
TASK:hamming
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<set>
#include<vector>
using namespace std;

int hamming(int a, int b)
{
	int result = 0;
	while (a != 0 && b != 0)
	{
		if ((a & 1) != (b & 1))
		{
			result++;
		}
		a >>= 1;
		b >>= 1;
	}
	while (a != 0)
	{
		result += (a & 1);
		a >>= 1;
	}
	while (b != 0)
	{
		result += (b & 1);
		b >>= 1;
	}
	return result;
}

int main()
{
	ifstream fin("hamming.in");
	ofstream fout("hamming.out");
	int n, b, d;
	fin >> n >> b >> d;
	int max = 1 << b;
	set<int> result;
	result.insert(0);
	int start = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < max; j++)
		{
			bool isfind = true;
			if (result.find(j) != result.end())
				continue;
			for (set<int> ::iterator iter = result.begin(); iter != result.end(); iter++)
			{
				int tmp = *iter;
				if (hamming(j, tmp) < d)
				{
					isfind = false;
					break;
				}
			}
			if (isfind)
			{
				result.insert(j);
				break;
			}
		}
	}
	int t = 1;
	vector<int> r;
	for (set<int> ::iterator iter = result.begin(); iter != result.end(); iter++, t++)
		r.push_back(*iter);
	for (int i = 1; i <= r.size(); i++)
	{
		fout << r[i - 1];
		if (!(i % 10 == 0 || i == r.size()))
			fout << ' ';
		else
			fout << endl;
	}
	//system("pause");
	return 0;
}
