/*
ID:chac161
TASK:castle
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
int m, n;
int **castle, **room;

vector<int> findemptyroom()
{
	vector<int> result;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (room[i][j] == 0)
			{
				result.push_back(i); result.push_back(j);
				return result;
			}
		}
	}
	result.push_back(-1);
	return result;
}

int main()
{
	ifstream fin("castle.in");
	ofstream fout("castle.out");
	fin >> m >> n;
	room = new int*[n];
	castle = new int*[n];
	for (int i = 0; i < n; i++)
	{
		room[i] = new int[m]();
		castle[i] = new int[m];
		for (int j = 0; j < m; j++)
			fin >> castle[i][j];
	}
	queue<pair<int, int> > place;
	int key;
	for (key = 1;; key++)
	{
		vector<int> now = findemptyroom();
		if (now[0] == -1)
			break;
		pair<int, int> tmp = make_pair(now[0], now[1]);
		room[now[0]][now[1]] = key;
		place.push(tmp);
		while (!place.empty())
		{
			pair<int, int> start = place.front();
			place.pop();
			if ((castle[start.first][start.second] & 1) == 0 && room[start.first][start.second - 1] == 0)
			{
				room[start.first][start.second - 1] = key;
				tmp = make_pair(start.first, start.second - 1);
				place.push(tmp);
			}
			if ((castle[start.first][start.second] & 2) == 0 && room[start.first - 1][start.second] == 0)
			{
				room[start.first - 1][start.second] = key;
				tmp = make_pair(start.first - 1, start.second);
				place.push(tmp);
			}
			if ((castle[start.first][start.second] & 4) == 0 && room[start.first][start.second + 1] == 0)
			{
				room[start.first][start.second + 1] = key;
				tmp = make_pair(start.first, start.second + 1);
				place.push(tmp);
			}
			if ((castle[start.first][start.second] & 8) == 0 && room[start.first + 1][start.second] == 0)
			{
				room[start.first + 1][start.second] = key;
				tmp = make_pair(start.first + 1, start.second);
				place.push(tmp);
			}
		}
	}
	fout << key - 1<< endl;
	int *area = new int[key]();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			++area[room[i][j]];
	}
	int max = area[1];
	for (int i = 2; i < key; i++)
		max = max >= area[i] ? max : area[i];
	fout << max << endl;
	max = 0;
	char dir;
	int x, y;
	for (int j = 0; j < m; j++)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			if (i != 0 && (castle[i][j] & 2) == 2 && room[i][j] != room[i - 1][j])
			{
				if (max < area[room[i][j]] + area[room[i - 1][j]])
				{
					dir = 'N';
					x = i; y = j;
					max = area[room[i][j]] + area[room[i - 1][j]];
				}
			}
			if (j != m - 1 && (castle[i][j] & 4) == 4 && room[i][j] != room[i][j + 1])
			{
				if (max < area[room[i][j]] + area[room[i][j + 1]])
				{
					dir = 'E';
					x = i; y = j;
					max = area[room[i][j]] + area[room[i][j + 1]];
				}
			}
		}
	}
	fout << max << endl;
	fout << x + 1 << ' ' << y + 1 << ' ' << dir << endl;
	//system("pause");
	return 0;
}
