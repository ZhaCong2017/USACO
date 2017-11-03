/*
ID:chac161
TASK:prefix
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<queue>
#include<set>
using namespace std;

int main()
{
	ifstream fin("prefix.in");
	ofstream fout("prefix.out");
	vector<string> prefix;
	string tmp, s, pre = "";
	int result = 0;
	while (1)
	{
		fin >> tmp;
		if (tmp != ".")
			prefix.push_back(tmp);
		else
			break;
	}
	while (fin >> tmp)
	{
		s += tmp;
	}

	queue<int> status;
	bool *visit = new bool[s.length()]();
	status.push(0);
	visit[0] = true;
	while (!status.empty())
	{
		int now = status.front();
		status.pop();
		result = result > now ? result : now;
		for (int i = 0; i < prefix.size(); i++)
		{
			bool match = true;
			for (int j = 0; j < prefix[i].length(); j++)
			{
				if (s[now + j] != prefix[i][j])
				{
					match = false;
					break;
				}
			}
			if (match && visit[now + prefix[i].length()] == false)
			{
				status.push(now + prefix[i].length());
				visit[now + prefix[i].length()] = true;
			}
		}

	} 

	fout << result << endl;
	//system("pasue");
	return 0;
}
