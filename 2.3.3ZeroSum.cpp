/*
ID:chac161
TASK:zerosum
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<set>
using namespace std;

int main()
{
	ifstream fin("zerosum.in");
	ofstream fout("zerosum.out");
	string numtochar[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	string symbol[3] = { "-", "+", " " };
	int n;
	fin >> n;
	queue<int> computation;
	queue<string> formula;
	set<string>result;
	computation.push(1);
	formula.push("1");
	for (int i = 2; i <= n; i++)
	{
		int size = formula.front().length();
		while (size == formula.front().length())
		{
			string now = formula.front();
			string tmp;
			formula.pop();
			int com = computation.front();
			computation.pop();
			if (i == 2 || now[now.length() - 2] != ' ')
			{
				formula.push(now + symbol[2] + numtochar[i]);
				if (i != 2)
				{
					if (now[now.length() - 2] == '+')
						computation.push(com + i * 10 - 9);
					else
						computation.push(com - i * 10 + 9);
				}
				else
					computation.push(com * 10 + i);
			}
			formula.push(now + symbol[1] + numtochar[i]);
			computation.push(com + i);
			formula.push(now + symbol[0] + numtochar[i]);
			computation.push(com - i);
			if ((i == n && com + i * 10 - 9 == 0 && now[now.length() - 2] == '+') || (i == n && com - i * 10 + 9 == 0 && now[now.length() - 2] == '-'))
				result.insert(now + symbol[2] + numtochar[i]);
			if (i == n && com + i == 0)
				result.insert(now + symbol[1] + numtochar[i]);
			if (i == n && com - i == 0)
				result.insert(now + symbol[0] + numtochar[i]);
		}
	}

	for (set<string> ::iterator iter = result.begin(); iter != result.end(); iter++)
		fout << *iter << endl;
	//system("pasue");
	return 0;
}
