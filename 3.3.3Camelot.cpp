/*
ID:chac161
TASK:camelot
LANG:C++
*/

#include <iostream>
#include<fstream>
#include<vector>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
int m, n;
int kingx, kingy;
vector<int> pos_x, pos_y;
int dis[32][32][32][32];
int kingdis[32][32];
bool visit[32][32];
int moving[8][2] = { { 2, 1 }, { -2, 1 }, { 1, 2 }, { -1, 2 }, { 2, -1 }, { -2, -1 }, { 1, -2 }, { -1, -2 } };

int min(int a, int b)
{
	return a < b ? a : b;
}

void init()
{
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			for (int ii = 0; ii < 32; ii++)
			{
				for (int jj = 0; jj < 32; jj++)
				{
					dis[i][j][ii][jj] = 100000;
				}
			}
		}
	}
}

int allpath(int a, int b)
{
	int result = 100000;
	int tmp = 100000;
	int knight = 0;
	for (int j = 0; j < pos_x.size(); j++)
		knight += dis[pos_x[j]][pos_y[j]][a][b];

	for (int i = 0; i < pos_x.size(); i++)
	{
		for (int ii = kingx - 2; ii <= kingx + 2; ii++)
		{
			for (int jj = kingy - 2; jj <= kingy + 2; jj++)
			{
				if (ii < 1 || jj < 1 || ii > n || jj > m)
					continue;
				tmp = min(tmp, kingdis[ii][jj] + dis[pos_x[i]][pos_y[i]][ii][jj] + dis[ii][jj][a][b]);
				//tmp += dis[ii][jj][a][b];
				tmp = tmp + knight - dis[pos_x[i]][pos_y[i]][a][b];
				result = min(result, tmp);
			}
		}
	}
	return result;
}

void kingdfs(int a, int b)
{
	for (int i = a - 2; i <= a + 2; i++)
	{
		for (int j = b - 2; j <= b + 2; j++)
		{
			if (i >= 1 && j >= 1 && i <= n && j <= m)
			{
				if (abs(a - i) == 2 || abs(b - j) == 2)
					kingdis[i][j] = 2;
				else if (a - i == 0 && b - j == 0)
					kingdis[i][j] = 0;
				else
					kingdis[i][j] = 1;
			}
		}
	}
}

void dfs(int a, int b)
{
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int> > position;
	queue<int> steps;
	position.push(make_pair(a, b));
	steps.push(0);
	visit[a][b] = true;
	dis[a][b][a][b] = 0;
	while (!position.empty())
	{
		pair<int, int> now = position.front();
		int nowstep = steps.front();
		position.pop(); steps.pop();
		int x, y;
		for (int i = 0; i < 8; i++)
		{
			x = now.first + moving[i][0];
			y = now.second + moving[i][1];
			if (x >= 1 && y >= 1 && x <= n && y <= m && (!visit[x][y]))
			{
				visit[x][y] = true;
				dis[a][b][x][y] = nowstep + 1;
				steps.push(nowstep + 1);
				position.push(make_pair(x, y));
			}
		}
	}
}

int main()
{
	ifstream fin("camelot.in");
	ofstream fout("camelot.out");
	init();
	char x;
	int y;
	fin >> m >> n;
	fin >> x >> kingy;
	kingx = x - 'A' + 1;
	while (fin >> x)
	{
		x -= ('A' - 1);
		fin >> y;
		pos_x.push_back(x);
		pos_y.push_back(y);

	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			dfs(i, j);
	}
	kingdfs(kingx, kingy);

	int result = 100000;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			result = min(result, allpath(i, j));
	}

	if (pos_x.size() == 0)
		fout << 0 << endl;
	else
		fout << result << endl;

	//system("pause");
	return 0;
}
