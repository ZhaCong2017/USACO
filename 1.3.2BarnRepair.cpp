/*
ID:chac161
TASK:barn1
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<map>
#include<algorithm>
using namespace std;

class node{
public:
	int distance;
	int place;
};

void sort(node *dis, int c)
{
	for (int i = 0; i < c; i++)
	{
		for (int j = i + 1; j < c; j++)
			if (dis[i].distance < dis[j].distance)
			{
				swap(dis[i].distance, dis[j].distance);
				swap(dis[i].place, dis[j].place);
			}
	}
}

int main()
{
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	int m, s, c;
	int tmp;
	fin >> m >> s >> c;
	if (m >= c)
	{
		fout << c << endl;
		return 0;
	}
	int *stalls = new int[c];
	node *dis = new node[c];
	map<int, int> cut;
	for (int i = 0; i < c; i++)
	{
		fin >> tmp;
		stalls[i] = tmp;
	}
	sort(stalls, stalls + c);
	for (int i = 0; i < c - 1; i++)
	{
		dis[i].distance = stalls[i + 1] - stalls[i];
		dis[i].place = i;
	}
	sort(dis, c - 1);
	for (int i = 0; i < m - 1; i++)
		cut[dis[i].place] = dis[i].distance;

	int now = 0, result = 0;
	int i = 0;
	for (map<int, int> ::iterator iter = cut.begin(); i < m - 1; iter++, i++)
	{
		result += (stalls[iter->first] - stalls[now] + 1);
		now = iter->first + 1;
	}
	result += (stalls[c - 1] - stalls[now] + 1);
	fout << result << endl;
	//system("pause");
	return 0;
}
