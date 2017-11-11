/*
ID:chac161
TASK:contact
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<set>
#include<vector>
using namespace std;
map<string, int> coun;
int a, b, n;

int main()
{
	ifstream fin("contact.in");
	ofstream fout("contact.out");
	char s[100];
	string aim;
	fin >> a >> b >> n;
	fin.getline(s, 100);
	while (fin.getline(s, 100))
		aim += s;

	for (int i = a; i <= b; i++)
	{
		for (int j = 0; i + j <= aim.length(); j++)
		{
			string tmp = aim.substr(j, i);
			if (coun.find(tmp) != coun.end())
				coun[tmp]++;
			else
				coun[tmp] = 1;
		}
	}
	
	map<int, map<int, set<string> > > result;
	int t;
	for (map<string, int> ::iterator iter = coun.begin(); iter != coun.end(); iter++)
		result[iter->second][iter->first.length()].insert(iter->first);

	map<int, vector<string> > output;
	t = 0;
	for (map<int, map<int, set<string> > > ::iterator iter = --result.end(); ; iter--)
	{
		vector<string> vs;
		int now = iter->first;
		for (map<int, set<string> >::iterator it1 = iter->second.begin(); it1 != iter->second.end(); it1++)
		{
			for (set<string> ::iterator it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
			{
				vs.push_back(*it2);
			}
		}
		output[now] = vs;
		t++;
		if (t == n)
			break;
		if (iter == result.begin())
			break;
	}

	for (map<int, vector<string> >::iterator iter = --output.end(); ; iter--)
	{
		fout << iter->first << endl;
		int outputtime = 1;
		for (int i = 0; i < iter->second.size(); i++)
		{
			fout << iter->second[i];
			if (outputtime % 6 == 0)
				fout << endl;
			else if (outputtime != iter->second.size())
				fout << ' ';
			outputtime++;
		}
		if ((outputtime - 1)% 6 != 0)
			fout << endl;
		if (iter == output.begin())
			break;
	}
	//system("pasue");
	return 0;
}
