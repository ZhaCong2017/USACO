/*
ID:chac161
TASK:fence
LANG:C++
*/

#include <iostream>
#include<fstream>
#include<vector>
using namespace std;
ifstream fin("fence.in");
ofstream fout("fence.out");
int node[505][505];
int num[505];
int maxn, minn;
vector<int>result;

void dfs(int x)
{
	//result.push_back(x);
	if (num[x] == 0)
	{
		result.push_back(x);
		return;
	}
	int next;
	while (num[x])
	{
		for (int i = minn; i <= maxn; i++)
		{
			if (node[x][i] > 0)
			{
				next = i;
				break;
			}
		}
		node[x][next]--;
		node[next][x]--;
		num[x]--;
		num[next]--;
		dfs(next);
	}
	result.push_back(x);
}

int main()
{
	int n, a, b;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> a >> b;
		minn = minn < a ? minn : a;
		minn = minn < b ? minn : b;
		maxn = maxn > a ? maxn : a;
		maxn = maxn > b ? maxn : b;
		node[a][b]++;
		node[b][a]++;
		num[a]++;
		num[b]++;
	}

	bool isodd = false;
	int i;
	for (i = minn; i <= maxn; i++)
	{
		if (num[i] % 2 == 1)
		{
			isodd = true;
			break;
		}
	}
	if (!isodd)
	{
		for (int j = minn; j < maxn; j++)
		{
			if (num[j] > 0)
			{
				i = j;
				break;
			}
		}
	}
	dfs(i);

	for (int i = result.size() - 1; i >= 0; i--)
		fout << result[i] << endl;
	//system("pause");
	return 0;
}
