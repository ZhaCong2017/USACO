/*
ID:chac161
TASK:namenum
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;

ifstream fin("namenum.in");
ofstream fout("namenum.out");
map<string, int> name;
char Map[8][3] = { { 'A', 'B', 'C' }, { 'D', 'E', 'F' }, { 'G', 'H', 'I' }, { 'J', 'K', 'L' },
				   { 'M', 'N', 'O' }, { 'P', 'R', 'S' }, { 'T', 'U', 'V' }, { 'W', 'X', 'Y' } };
string n;
int len;
bool have = false;

void buildname(string now, int position)
{
	for (int i = 0; i < 3; i++)
	{
		now += Map[n[position] - '2'][i];
		if (position == len)
		{
			if (name.find(now) != name.end())
			{
				have = true;
				fout << now << endl;
				now = now.substr(0, now.length() - 1);
				continue;
			}
		}
		else
			buildname(now, position + 1);
		now = now.substr(0, now.length() - 1);
	}
}

int main()
{
	fin >> n;
	len = n.length() - 1;
	ifstream datain("dict.txt");
	string tmp;
	for (int i = 0; i < 4617; i++)
	{
		datain >> tmp;
		name[tmp] = i;
	}

	string now = "";
	buildname(now, 0);
	if (!have)
		fout << "NONE" << endl;
	//system("pause");
	return 0;
}
