/*
ID:chac161
TASK:beads
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

string color;

class position
{
public:
	int leftr;
	int leftb;
	int rightr;
	int rightb;
	position()
	{
		leftr = leftb = rightr = rightb = 0;
	}
};

int findcolor(int x)
{
	char c = color[x % color.length()];
	if (c == 'w')
		return 0;
	else if (c == 'r')
		return 1;
	else
		return 2;
}

int main()
{
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	int n;
	fin >> n >> color;
	position *pos = new position[2 * n + 1];
	for (int i = 0; i < 2 * n; i++)
	{
		int c = findcolor(i);
		switch (c)
		{
		case 0:
			pos[i + 1].leftr = pos[i].leftr + 1;
			pos[i + 1].leftb = pos[i].leftb + 1;
			break;
		case 1:
			pos[i + 1].leftr = pos[i].leftr + 1;
			break;
		case 2:
			pos[i + 1].leftb = pos[i].leftb + 1;
			break;
		}
	}
	for (int i = 2 * n - 1; i >= 0; i--)
	{
		int c = findcolor(i);
		switch (c)
		{
		case 0:
			pos[i].rightr = pos[i + 1].rightr + 1;
			pos[i].rightb = pos[i + 1].rightb + 1;
			break;
		case 1:
			pos[i].rightr = pos[i + 1].rightr + 1;
			break;
		case 2:
			pos[i].rightb = pos[i + 1].rightb + 1;
			break;
		}
	}
	int result = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		int tmp = max(pos[i].leftb + pos[i].rightr, pos[i].leftr + pos[i].rightb);
		result = result < tmp ? tmp : result;
	}
	if (result > n)
		fout << n << endl;
	else
		fout << result << endl;
	//system("pause");
	return 0;
}
