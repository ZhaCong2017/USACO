/*
ID:chac161
TASK:ditch
LANG:C++
*/

#include <iostream>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;

int mp[205][205];
int n, m;
int pre[205];

int min(int a, int b)
{
	return a < b ? a : b;
}

bool BFS()
{
	queue<int> node;
	vector<bool> visited(m + 5, false);
	for (int i = 0; i < 205; i++)
		pre[i] = -1;
	pre[1] = 1;
	visited[1] = true;
	node.push(1);
	while (!node.empty())
	{
		int now = node.front();
		node.pop();
		for (int i = 1; i <= m; i++)
		{
			if (mp[now][i] > 0 && visited[i] == false)
			{
				pre[i] = now;
				visited[i] = true;
				if (i == m)
					return true;
				node.push(i);
			}

		}
	}
	return false;
}

int maxflow()
{
	int result = 0;
	while (BFS())
	{
		int d = 1000000;
		for (int i = m; i != 1; i = pre[i])
			d = min(d, mp[pre[i]][i]);
		result += d;
		for (int i = m; i != 1; i = pre[i])
		{
			mp[pre[i]][i] -= d;
			mp[i][pre[i]] += d;
		}
	}
	return result;
}

int main()
{
	ifstream fin("ditch.in");
	ofstream fout("ditch.out");
	fin >> n >> m;
	int a, b, len;
	for (int i = 0; i < n; i++)
	{
		fin >> a >> b >> len;
		mp[a][b] += len;
	}
	fout << maxflow() << endl;
	//system("pause");
	return 0;
}
