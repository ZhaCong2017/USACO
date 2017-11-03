/*
ID:chac161
TASK:lamps
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<queue>
#include<set>
using namespace std;
vector<int> on;
vector<int> off;

string button1(string lamp)
{
	string result;
	for (int i = 0; i < lamp.length(); i++)
	{
		/*if (lamp[i] == '1')
			lamp[i] = '0';
		else
			lamp[i] = '1';*/
		result += ((lamp[i] - '0') ^ 1) + '0';
	}
	return result;
}

string button2(string lamp)
{
	string result;
	for (int i = 0; i < lamp.length(); i++)
	{
		result += lamp[i];
		if ((i + 1) % 2 == 1)
		{
			result[i] = ((lamp[i] - '0') ^ 1) + '0';
		}
	}
	return result;
}

string button3(string lamp)
{
	string result;
	for (int i = 0; i < lamp.length(); i++)
	{
		result += lamp[i];
		if ((i + 1) % 2 == 0)
		{
			result[i] = ((lamp[i] - '0') ^ 1) + '0';
		}
	}
	return result;
}

string button4(string lamp)
{
	string result;
	for (int i = 0; i < lamp.length(); i++)
	{
		result += lamp[i];
		if (i % 3 == 0)
		{
			result[i] = ((lamp[i] - '0') ^ 1) + '0';
		}
	}
	return result;
}

bool isfind(string lamp)
{
	for (int i = 0; i < on.size(); i++)
	{
		if (lamp[on[i] - 1] != '1')
			return false;
	}
	for (int i = 0; i < off.size(); i++)
	{
		if (lamp[off[i] - 1] != '0')
			return false;
	}
	return true;
}

int main()
{
	ifstream fin("lamps.in");
	ofstream fout("lamps.out");
	int n, c, tmp;
	string lamp;
	fin >> n >> c;
	for (int i = 0; i < n; i++)
		lamp += '1';
	while (1)
	{
		fin >> tmp;
		if (tmp != -1)
			on.push_back(tmp);
		else
			break;
	}
	while (1)
	{
		fin >> tmp;
		if (tmp != -1)
			off.push_back(tmp);
		else
			break;
	}
	set<string> visit;
	set<string> result;
	queue<string> status;
	queue<int> action;
	status.push(lamp);
	action.push(0);
	visit.insert(lamp);
	if (isfind(lamp))
		result.insert(lamp);
	while (!status.empty())
	{
		string now = status.front();
		string x;
		status.pop();
		int act = action.front();
		action.pop();
		x = button1(now);
		if (isfind(x) && act + 1 <= c)
			result.insert(x);
		if (visit.find(x) == visit.end() && act + 1 <= c)
		{
			visit.insert(x);
			status.push(x);
			action.push(act + 1);
		}

		x = button2(now);
		if (isfind(x) && act + 1 <= c)
			result.insert(x);
		if (visit.find(x) == visit.end() && act + 1 <= c)
		{
			visit.insert(x);
			status.push(x);
			action.push(act + 1);
		}

		x = button3(now);
		if (isfind(x) && act + 1 <= c)
			result.insert(x);
		if (visit.find(x) == visit.end() && act + 1 <= c)
		{
			visit.insert(x);
			status.push(x);
			action.push(act + 1);
		}

		x = button4(now);
		if (isfind(x) && act + 1 <= c)
			result.insert(x);
		if (visit.find(x) == visit.end() && act + 1 <= c)
		{
			visit.insert(x);
			status.push(x);
			action.push(act + 1);
		}
	}
	
	for (set<string> ::iterator iter = result.begin(); iter != result.end(); iter++)
		fout << *iter << endl;
	if (result.empty())
		fout << "IMPOSSIBLE" << endl;
	//system("pasue");
	return 0;
}
