/*
ID:chac161
TASK:milk2
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<map>
using namespace std;

int main()
{
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	int n;
	fin >> n;
	int start, end;
	map<int, int>time;
	for (int i = 0; i < n; i++)
	{
		fin >> start >> end;
		map<int, int> ::iterator iter = time.find(start);
		if (iter == time.end())
			time[start] = end;
		else if (end > iter->second)
			iter->second = end;
	}
	int maxin = 0, maxout = 0;
	end = 0;
	for (map<int, int> ::iterator i = time.begin(); i != time.end(); i++)
	{
		map<int, int> ::iterator tmp = i;
		for (map<int, int> ::iterator j = ++tmp; j != time.end();)
		{
			if (j->second <= i->second)
				time.erase(j++);
			else if (j->first <= i->second)
			{
				i->second = j->second;
				time.erase(j++);
			}
			else
				++j;
		}
	}
	for (map<int, int> ::iterator iter = time.begin(); iter != time.end(); iter++)
	{
		maxin = maxin > iter->second - iter->first ? maxin : iter->second - iter->first;
		if (end != 0)
			maxout = maxout > iter->first - end ? maxout : iter->first - end;
		end = iter->second;
	}
	fout << maxin << ' ' << maxout << endl;
	//system("pause");
	return 0;
}
