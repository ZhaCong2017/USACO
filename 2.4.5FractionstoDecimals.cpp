/*
ID:chac161
TASK:fracdec
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

string tostring(int a)
{
	string result;
	while (a)
	{
		result += a % 10 + '0';
		a /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	ifstream fin("fracdec.in");
	ofstream fout("fracdec.out");
	vector<vector<int> > map;
	vector<vector<int> > position;
	for (int i = 0; i < 10; i++)
	{
		vector<int> tmp;
		vector<int> tmp1;
		map.push_back(tmp);
		position.push_back(tmp1);
	}
	int a, b, now;
	int start = -1;
	string result;
	fin >> a >> b;
	for (int i = min(a, b); i > 1; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			a /= i;
			b /= i;
		}
	}
	if (a >= b)
	{
		now = a % b * 10;
		result += tostring(a / b);
	}
	else
	{
		now = a * 10;
		result += '0';
	}
	result += '.';
	map[now / b].push_back(now);
	position[now / b].push_back(result.length());
	if (now == 0)
		result += '0';
	else
	{
		while (1)
		{
			result += now / b + '0';
			now = now % b * 10;
			if (now == 0)
			{
				start = -1;
				break;
			}
			bool have = false;
			for (int i = 0; i < map[now / b].size(); i++)
			{
				if (now == map[now / b][i])
				{
					have = true;
					start = position[now / b][i];
					break;
				}
			}
			if (!have)
			{
				map[now / b].push_back(now);
				position[now / b].push_back(result.length());
			}
			else
				break;
		}
	}

	if (start != -1)
	{
		result += ") ";
		for (int i = result.length() - 1; i >= start; i--)
			result[i] = result[i - 1];
		result[start] = '(';
	}

	int pos = 1;
	for (; pos <= result.length(); pos++)
	{
		fout << result[pos - 1];
		if (pos % 76 == 0)
			fout << endl;
	}
	if (pos % 76 != 0)
		fout << endl;

	//system("pasue");
	return 0;
}
