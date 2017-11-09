/*
ID:chac161
TASK:agrinet
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int farms[105][105];
bool visit[105];

int main()
{
	ifstream fin("agrinet.in");
	ofstream fout("agrinet.out");
	int n, result = 0, tmp;
	vector<int> start, end;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			fin >> farms[i][j];
	}

	visit[0] = true;
	for (int i = 1; i < n; i++)
	{
		start.push_back(0);
		end.push_back(i);
	}

	while (!start.empty())
	{
		int a, b = 0, len = 1000000;
		vector<int> ::iterator iter1 = start.begin(), iter2 = end.begin(), n1, n2;
		for (; iter1 != start.end(); iter1++, iter2++)
		{
			if (len > farms[*iter1][*iter2] && visit[*iter1] && !visit[*iter2])
			{
				len = farms[*iter1][*iter2]; a = *iter1; b = *iter2;
				n1 = iter1; n2 = iter2;
			}
		}
		visit[b] = true;
		result += len;
		start.erase(n1);
		end.erase(n2);
		for (int i = 0; i < n; i++)
		{
			if (!visit[i])
			{
				start.push_back(b);
				end.push_back(i);
			}
		}

		bool isdone = true;
		for (int i = 0; i < n; i++)
		{
			if (!visit[i])
				isdone = false;
		}
		if (isdone)
			break;
	}

	fout << result << endl;
	//system("pasue");
	return 0;
}
