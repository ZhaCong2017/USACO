/*
ID:chac161
TASK:maze1
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<queue>
#include<cstring>
using namespace std;
char map[210][210];
int result[105][105];
bool visit[105][105];

void init()
{
	for (int i = 0; i < 105; i++)
	{
		for (int j = 0; j < 105; j++)
			result[i][j] = 10000;
	}
}

int main()
{
	ifstream fin("maze1.in");
	ofstream fout("maze1.out");
	init(); 
	int h, w;
	fin >> w >> h;
	int gate[2][2];
	int start = 0;
	char s[120];
	fin.getline(s, 1000);
	for (int i = 0; i < 2 * h + 1; i++)
	{
		fin.getline(s, 500);
		for (int j = 0; j < 2 * w + 1; j++)
		{
			map[i][j] = s[j];
			if (map[i][j] == ' ' && (i == 0 || i == 2 * h || j == 0 || j == 2 * w))
			{
				gate[start][0] = i;
				gate[start][1] = j;
				start++;
			}
		}
	}

	for (int i = 0; i < 2; i++)
	{
		memset(visit, false, sizeof(visit));
		queue<int> x, y, travel;
		x.push((gate[i][0] - 1) / 2);
		y.push((gate[i][1] - 1) / 2);
		travel.push(1);
 		while (!x.empty())
		{
			int nowx = x.front();
			int nowy = y.front();
			int dis = travel.front();
			x.pop();
			y.pop();
			travel.pop();
			if (visit[nowx][nowy])
				continue;
			visit[nowx][nowy] = true;
			result[nowx][nowy] = dis < result[nowx][nowy] ? dis : result[nowx][nowy];

			if (nowx != 0 && map[nowx * 2][nowy * 2 + 1] == ' ' && visit[nowx - 1][nowy] == false)
			{
				x.push(nowx - 1);
				y.push(nowy);
				travel.push(dis + 1);
			}

			if (nowx != h - 1 && map[(nowx + 1) * 2][nowy * 2 + 1] == ' ' && visit[nowx + 1][nowy] == false)
			{
				x.push(nowx + 1);
				y.push(nowy);
				travel.push(dis + 1);
			}


			if (nowy != 0 && map[nowx * 2 + 1][nowy * 2] == ' '  && visit[nowx][nowy - 1] == false)
			{
				x.push(nowx);
				y.push(nowy - 1);
				travel.push(dis + 1);
			}

			if (nowy != w - 1 && map[nowx * 2 + 1][(nowy + 1) * 2] == ' ' && visit[nowx][nowy + 1] == false)
			{
				x.push(nowx);
				y.push(nowy + 1);
				travel.push(dis + 1);
			}
		}
	}
	int max = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			max = max > result[i][j] ? max : result[i][j];
	}
	fout << max << endl;
	//system("pasue");
	return 0;
}
