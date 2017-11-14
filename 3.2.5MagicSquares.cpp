/*
ID:chac161
TASK:msquare
LANG:C++
*/

#include <iostream>
#include<fstream>
#include<queue>
#include<set>
#include<vector>
#include<string>
using namespace std;
vector<int> aim(8);

vector<int> A(vector<int> start)
{
	for (int i = 0, j = 7; j > i; j--, i++)
	{
		int tmp = start[i];
		start[i] = start[j];
		start[j] = tmp;
	}
	return start;
}

vector<int> B(vector<int> start)
{
	int tmp = start[3];
	for (int i = 3; i > 0; i--)
		start[i] = start[i - 1];
	start[0] = tmp;
	tmp = start[4];
	for (int i = 4; i < 7; i++)
		start[i] = start[i + 1];
	start[7] = tmp;
	return start;
}

vector<int> C(vector<int> start)
{
	int tmp = start[1];
	start[1] = start[6];
	start[6] = start[5];
	start[5] = start[2];
	start[2] = tmp;
	return start;
}

bool issame(vector<int> start)
{
	for (int i = 0; i < 8; i++)
	{
		if (start[i] != aim[i])
			return false;
	}
	return true;
}

int main()
{
	ifstream fin("msquare.in");
	ofstream fout("msquare.out");
	vector<int> start(8);
	string s;
	for (int i = 0; i < 8; i++)
	{
		fin >> aim[i];
		start[i] = i + 1;
	}
	if (issame(start))
	{
		fout << 0 << endl;
		fout << endl;
		return 0;
	}
	set<vector<int> > visit;
	queue<int> action;
	queue<vector<int> > status;
	queue<string> operation;
	visit.insert(start);
	status.push(start);
	action.push(0);
	operation.push(s);
	int act; string operate;

	while (!status.empty())
	{
		vector<int> now = status.front();
		act = action.front();
		operate = operation.front();
		status.pop();
		action.pop();
		operation.pop();

		vector<int> tmp = A(now);
		if (issame(tmp))
		{
			operate += "A";
			act += 1;
			break;
		}
		if (visit.find(tmp) == visit.end())
		{
			visit.insert(tmp);
			status.push(tmp);
			action.push(act + 1);
			operation.push(operate + "A");
		}

		tmp = B(now);
		if (issame(tmp))
		{
			operate += "B";
			act += 1;
			break;
		}
		if (visit.find(tmp) == visit.end())
		{
			visit.insert(tmp);
			status.push(tmp);
			action.push(act + 1);
			operation.push(operate + "B");
		}

		tmp = C(now);
		if (issame(tmp))
		{
			operate +=  "C";
			act += 1;
			break;
		}
		if (visit.find(tmp) == visit.end())
		{
			visit.insert(tmp);
			status.push(tmp);
			action.push(act + 1);
			operation.push(operate + "C");
		}
	}

	fout << act << endl;
	int i;
	for (i = 1; i <= operate.length(); i++)
	{
		fout << operate[i - 1];
		if (i % 60 == 0)
			fout << endl;
	}
	if (i % 60 != 0)
		fout << endl;
	//system("pause");
	return 0;
}
