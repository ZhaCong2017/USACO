/*
ID:chac161
TASK:comehome
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<queue>
using namespace std;
#define MAX 100000000
int map[60][60];
int result[60];

void init()
{
	for (int i = 0; i < 60; i++)
	{
		result[i] = MAX;
		for (int j = 0; j < 60; j++)
			map[i][j] = MAX;
	}
	result[51] = 0;
}

int main()
{
	ifstream fin("comehome.in");
	ofstream fout("comehome.out");
	int n;
	char a, b;
	int start, end, dis;
	fin >> n;
	init();
	for (int i = 0; i < n; i++)
	{
		fin >> a >> b >> dis;
		if (a >= 'a' && a <= 'z')
			start = a - 'a';
		else
			start = a - 'A' + 26;
		if (b >= 'a' && b <= 'z')
			end = b - 'a';
		else
			end = b - 'A' + 26;
		if (map[start][end] > dis)
		{
			map[start][end] = dis;
			map[end][start] = dis;
		}
	}
	queue<int> node;
	node.push(51);

	while (!node.empty())
	{
		int now = node.front();
		node.pop();
		for (int i = 0; i < 51; i++)
		{
			if (result[i] > result[now] + map[now][i])
			{
				result[i] = result[now] + map[now][i];
				node.push(i);
			}
		}
	}
	int min = MAX;
	char cow;
	for (int i = 26; i < 51; i++)
	{
		if (min > result[i])
		{
			min = result[i];
			cow = i + 'A' - 26;
		}
	}
	fout << cow << ' ' << min << endl;
	//system("pasue");
	return 0;
}
