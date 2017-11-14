/*
ID:chac161
TASK:butter
LANG:C++
*/

#include <iostream>
#include<fstream>
#include<vector>
#include<cstring>
#include<set>
#include<map>
using namespace std;
#define MAX 10000000;
int cow[505], pastures[805][805], n, p, c, compu[805][805], path[805][805];
vector<vector<pair<int, int> > > edge(805);

void init()
{
	for (int i = 0; i < 805; i++)
	{
		for (int j = 0; j < 805; j++)
		{
			compu[i][j] = pastures[i][j] = MAX;
			if (i == j)
				compu[i][j] = 0;
		}
	}
}

int getlength(int x)
{
	int result = 0;
	for (int i = 0; i < n; i++)
		result += pastures[cow[i]][x];
	return result;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

void dijkstra(int pos)
{
	if (pastures[pos][pos] == 0)
		return;
	pastures[pos][pos] = 0;
	map<int, vector<pair<int, int> > > road;
	bool visit[805];
	memset(visit, false, sizeof(visit));
	int dis[805];
	for (int i = 1; i <= p; i++) dis[i] = MAX;
	dis[pos] = 0; visit[pos] = true;

	for (int i = 0; i < edge[pos].size(); i++)
	{
		dis[edge[pos][i].first] = edge[pos][i].second;
		road[edge[pos][i].second].push_back(make_pair(pos, edge[pos][i].first));
	}

	while(road.size() != 0)
	{
		map<int, vector<pair<int, int> > >::iterator iter = road.begin();
		vector<pair<int, int> >::iterator  it = iter->second.begin();
		int a = it->first, b = it->second;
		iter->second.erase(it);
		if (iter->second.size() == 0)
			road.erase(iter);
		if (b == 94)
			b = 94;
		for (int i = 0; i < edge[b].size(); i++)
		{
  			dis[edge[b][i].first] = min(dis[edge[b][i].first], edge[b][i].second + dis[b]);
			if (!visit[edge[b][i].first] && visit[b] == false)
				road[dis[edge[b][i].first]].push_back(make_pair(b, edge[b][i].first));
		}	
		visit[b] = true;
	}
	for (int i = 1; i <= p; i++)
	{
		if (pastures[i][pos] > dis[i])
			pastures[pos][i] = pastures[i][pos] = dis[i];
	}
}

int main()
{
	ifstream fin("butter.in");
	ofstream fout("butter.out");
	init();
	int a, b, len;
	fin >> n >> p >> c;
	for (int i = 0; i < n; i++)
		fin >> cow[i];
	for (int i = 0; i < c; i++)
	{
		fin >> a >> b >> len;
		edge[a].push_back(make_pair(b, len));
		edge[b].push_back(make_pair(a, len));
		compu[a][b] = compu[b][a] = len;
	}
	for (int k = 0; k < n; k++)
		dijkstra(cow[k]);

	int result = MAX;
	int tmp;
	for (int i = 1; i <= p; i++)
	{
		tmp = getlength(i);
		result = result > tmp ? tmp : result;
	}
	fout << result << endl;

	//system("pause");
	return 0;
}
