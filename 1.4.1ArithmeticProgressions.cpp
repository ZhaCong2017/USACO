/*
ID:chac161
TASK:ariprog
LANG:C++
*/

#include<iostream>
#include<stdio.h>
#include<fstream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
bool noanswer = true;
bool *hashed;
int main()
{
	FILE *fin = fopen("ariprog.in", "r");
	FILE *fout = fopen("ariprog.out", "w");
	int n, m, x;
	fscanf(fin, "%d%d", &n, &m);
	hashed = new bool[m * m * 2]();
	map<int, int> bisquares;
	map<int, vector<int> > result;
	for (int i = 0; i <= m; i++)
	{
		for (int j = i; j <= m; j++)
		{
			x = i * i + j * j;
			bisquares[x] = 1;
			hashed[x] = true;
		}
	}
	int max = m * m + m * m;
	for (map<int, int> ::iterator iter = bisquares.begin(); iter != bisquares.end(); iter++)
	{
		map<int, int> ::iterator i = iter;
		for (i++; i != bisquares.end(); i++)
		{
			int t = 2, now = i->first;
			int dis = now - iter->first;
			if (now + dis * (n - 2) > max)
				break;
			bool isbisquares = true;
			for (int t = 2; t < n; t++)
			{
				now += dis;
				if (!hashed[now])
				{
					isbisquares = false;
					break;
				}
			}
			if (isbisquares)
			{
				noanswer = false;
				result[dis].push_back(iter->first);
			}
		}
	}

	for (map<int, vector<int> > ::iterator iter = result.begin(); iter != result.end(); iter++)
	{
		sort(iter->second.begin(), iter->second.end());
		for (int i = 0; i < iter->second.size(); i++)
			fprintf(fout, "%d %d\n", iter->second[i], iter->first);
	}
	if (noanswer)
		fprintf(fout, "NONE\n");
	//system("pause");
	return 0;
}
