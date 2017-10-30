/*
ID:chac161
TASK:milk3
LANG:C++
*/

#include<iostream>
#include<stdio.h>
#include<fstream>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

inline int hashed(int a, int b, int c)
{
	return a * 10000 + b * 100 + c;
}

int main()
{
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");
	int a, b, c;
	vector<int> start;
	fin >> a >> b >> c;
	start.push_back(0);
	start.push_back(0);
	start.push_back(c);
	queue<vector<int> > status;
	set<int> have;
	set<int> result;
	status.push(start);
	have.insert(hashed(0, 0, c));


	while (!status.empty())
	{
		vector<int> now = status.front();
		vector<int> tmp(3);
		status.pop();
		int h;
		int count;
		if (now[0] > 0 && b - now[1] > 0)
		{
			count = min(now[0], b - now[1]);
			h = hashed(now[0] - count, now[1] + count, now[2]);
			if (have.find(h) == have.end())
			{
				have.insert(h);
				tmp[0] = now[0] - count; tmp[1] = now[1] + count; tmp[2] = now[2];
				status.push(tmp);
			}
			if (now[0] - count == 0)
				result.insert(now[2]);
		}

		if (now[0] > 0 && c - now[2] > 0)
		{
			count = min(now[0], c - now[2]);
			h = hashed(now[0] - count, now[1], now[2] + count);
			if (have.find(h) == have.end())
			{
				have.insert(h);
				tmp[0] = now[0] - count; tmp[1] = now[1]; tmp[2] = now[2] + count;
				status.push(tmp);
			}
			if (now[0] - count == 0)
				result.insert(now[2] + count);
		}

		if (now[1] > 0 && c - now[2] > 0)
		{
			count = min(now[1], c - now[2]);
			h = hashed(now[0], now[1] - count, now[2] + count);
			if (have.find(h) == have.end())
			{
				have.insert(h);
				tmp[0] = now[0]; tmp[1] = now[1] - count; tmp[2] = now[2] + count;
				status.push(tmp);
			}
			if (now[0] == 0)
				result.insert(now[2] + count);
		}

		if (now[1] > 0 && a - now[0] > 0)
		{
			count = min(now[1], a - now[0]);
			h = hashed(now[0] + count, now[1] - count, now[2]);
			if (have.find(h) == have.end())
			{
				have.insert(h);
				tmp[0] = now[0] + count; tmp[1] = now[1] - count; tmp[2] = now[2];
				status.push(tmp);
			}
			if (now[0] + count == 0)
				result.insert(now[2]);
		}

		if (now[2] > 0 && a - now[0] > 0)
		{
			count = min(now[2], a - now[0]);
			h = hashed(now[0] + count, now[1], now[2] - count);
			if (have.find(h) == have.end())
			{
				have.insert(h);
				tmp[0] = now[0] + count; tmp[1] = now[1]; tmp[2] = now[2] - count;
				status.push(tmp);
			}
			if (now[0] + count == 0)
				result.insert(now[2] - count);
		}

		if (now[2] > 0 && b - now[1] > 0)
		{
			count = min(now[2], b - now[1]);
			h = hashed(now[0], now[1] + count, now[2] - count);
			if (have.find(h) == have.end())
			{
				have.insert(h);
				tmp[0] = now[0]; tmp[1] = now[1] + count; tmp[2] = now[2] - count;
				status.push(tmp);
			}
			if (now[0] == 0)
				result.insert(now[2] - count);
		}
	}

	vector<int> r;
	for (set<int> ::iterator iter = result.begin(); iter != result.end(); iter++)
		r.push_back(*iter);
	fout << r[0];
	for (int i = 1; i < r.size(); i++)
		fout << ' ' << r[i];
	fout << endl;
	//system("pause");
	return 0;
}
