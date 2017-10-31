/*
ID:chac161
TASK:frac1
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

pair<int, int> simpify(int a, int b)
{
	pair<int, int> result;
	int n = a;
	for (int i = 2; i <= n; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			a /= i;
			b /= i;
			i = 1;
		}
	}
	result.first = a; result.second = b;
	return result;
}

int main()
{
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");
	int n;
	fin >> n;
	map<float, pair<int, int> > result;
	pair<int, int> tmp = make_pair(0, 1);
	result[0] = tmp;
	tmp = make_pair(1, 1);
	result[1] = tmp;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			tmp = simpify(j, i);
			result[float(tmp.first) / tmp.second] = tmp;
		}
	}

	for (map<float, pair<int, int> > ::iterator iter = result.begin(); iter != result.end(); iter++)
	{
		fout << iter->second.first << '/' << iter->second.second << endl;
	}
	//system("pause");
	return 0;
}
