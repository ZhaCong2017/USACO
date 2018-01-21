/*
ID:chac161
TASK:stall4
LANG:C++
*/

#include <iostream>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;

#define MAX 510

int n, m;
int prefer[510][510];
int pre[510];

int min(int a, int b)
{
	return a < b ? a : b;
}

bool BFS(int s, int t)
{
	queue<int> node;
	vector<bool> visited(MAX, false);
	for (int i = 0; i < MAX; i++)
		pre[i] = -1;
	node.push(s);
	pre[s] = s;
	visited[s] = true;
	while (!node.empty())
	{
		int now = node.front();
		node.pop();
		for (int i = 0; i < MAX; i++)
		{
			if (prefer[now][i] > 0 && !visited[i])
			{
				pre[i] = now;
				visited[i] = true;
				if (i == t)
					return true;
				node.push(i);
			}
		}
	}
	return false;
}

int maxflow(int s, int t)
{
	int result = 0;
	while (BFS(s, t))
	{
		int d = 1000;
		for (int i = t; i != s; i = pre[i])
			d = min(d, prefer[pre[i]][i]);
		for (int i = t; i != s; i = pre[i])
		{
			prefer[pre[i]][i] -= d;
			prefer[i][pre[i]] += d;
		}
		result += d;
	}
	return result;
}

int main()
{
	ifstream fin("stall4.in");
	ofstream fout("stall4.out");
	fin >> n >> m;
	int s = 0;
	int t = n + m + 1;
	int num, k;
	for (int i = 1; i <= n; i++)
	{
		prefer[s][i] = 1;
		fin >> num;
		for (int j = 1; j <= num; j++)
		{
			fin >> k;
			prefer[i][k + n] = 1;
		}
	}
	for (int j = 1; j <= m; j++)
		prefer[j + n][t] = 1;
	fout << maxflow(s, t) << endl;

	//system("pause");
	return 0;
}
