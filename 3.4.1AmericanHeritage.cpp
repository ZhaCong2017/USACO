/*
ID:chac161
TASK:heritage
LANG:C++
*/

#include <iostream>
#include<fstream>
#include<string>
using namespace std;
ifstream fin("heritage.in");
ofstream fout("heritage.out");
string pre;

void findpost(string in)
{
	if (in.empty())
		return;
	char mid = pre[0];
	int i;
	pre = pre.substr(1, pre.length() - 1);
	for (i = 0; i < in.length(); i++)
	{
		if (in[i] == mid)
			break;
	}
	if (i != 0)
		findpost(in.substr(0, i));
	if (i != in.length() - 1)
		findpost(in.substr(i + 1));
	fout << mid;
}

int main()
{
	string in;
	fin >> in >> pre;
	findpost(in);
	fout << endl;

	//system("pause");
	return 0;
}
