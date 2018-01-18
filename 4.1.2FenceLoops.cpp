/*
ID:chac161
TASK:fence6
LANG:C++
*/

#include <iostream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
using namespace std;

int road[105][105];
int dis[105][105];
vector<set<int> > node;

int min(int a, int b)
{
	return a < b ? a : b;
}

int same(set<int> a)
{	
	for (int i = 0; i < node.size(); i++)
	{
		if (a.size() != node[i].size())
			continue;
		bool issame = true;
		for (set<int>::iterator it1 = a.begin(), it2 = node[i].begin(); it1 != a.end(); it1++, it2++)
		{
			if (*it1 != *it2)
			{
				issame = false;
				break;;
			}
		}
		if (issame)
			return i;
		else
			continue;
	}
	return -1;
}

int floyd(int n)
{
	int result = 1000000;
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < k; i++)
		{
			for (int j = i + 1; j < k; j++)
			{
				result = min(result, dis[i][j] + road[j][k] + road[i][k]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
			}
		}
	}
	return result;
}

int main()
{
	ifstream fin("fence6.in");
	ofstream fout("fence6.out");

	for (int i = 0; i < 105; i++)
	{
		for (int j = 0; j < 105; j++)
			road[i][j] = dis[i][j] = 10000000;
	}

	int n;
	fin >> n;
	int num, len, a, b, edge;
	for (int i = 0; i < n; i++)
	{
		set<int> node1, node2;
		fin >> num >> len >> a >> b;
		node1.insert(num);
		node2.insert(num);
		for (int j = 0; j < a; j++)
		{
			fin >> edge;
			node1.insert(edge);
		}
		int node_n1 = same(node1);
		if (node_n1 == -1)
		{
			node.push_back(node1);
			node_n1 = node.size() - 1;
		}
		for (int j = 0; j < b; j++)
		{
			fin >> edge;
			node2.insert(edge);
		}
		int node_n2 = same(node2);
		if (node_n2 == -1)
		{
			node.push_back(node2);
			node_n2= node.size() - 1;
		}
		dis[node_n1][node_n2] = dis[node_n2][node_n1] = road[node_n1][node_n2] = road[node_n2][node_n1] = len;
	}

	fout << floyd(n) << endl;
	//system("pause");
	return 0;
}
