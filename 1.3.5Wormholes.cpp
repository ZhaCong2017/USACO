/*
ID:chac161
TASK:wormhole
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<map>
#include<math.h>
using namespace std;
int n, *x, *y, *rightnext;
int result = 0;

bool istrapped(int *pair)
{
	for (int i = 0; i < n; i++)
	{
		int pos = i;
		for (int j = 0; j < n; j++)
		{
			pos = rightnext[pair[pos]];
			if (pos == -1)
				break;
		}
		if (pos != -1)
			return true;
	}
	return false;
}

void buildpair(int *pair)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (pair[i] == -1)
			break;
	}
	if (i >= n)
	{
		if (istrapped(pair))
			result++;
	}
	for (int j = i + 1; j < n; j++)
	{
		if (pair[j] == -1)
		{
			pair[i] = j;
			pair[j] = i;
			buildpair(pair);
			pair[i] = pair[j] = -1;
		}
	}
}

int main()
{
	ifstream fin("wormhole.in");
	ofstream fout("wormhole.out");
	int *pair;
	fin >> n;
	x = new int[n];
	y = new int[n];
	rightnext = new int[n];
	pair = new int[n];
	for (int i = 0; i < n; i++)
	{
		rightnext[i] = pair[i] = -1;
		fin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (y[i] == y[j] && x[j] > x[i])
			{
				if (rightnext[i] == -1 || x[rightnext[i]] > x[j])
					rightnext[i] = j;
			}
		}
	}

	buildpair(pair);
	fout << result << endl;

	//system("pause");
	return 0;
}
