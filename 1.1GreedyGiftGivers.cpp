/*
ID:chac161
TASK:gift1
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;

int main()
{
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");
	int n, money, num;
	fin >> n;
	int *wallet = new int[n]();
	cout << wallet[0] << endl;
	string name;
	map<string, int> namepair;
	for (int i = 0; i < n; i++)
	{
		fin >> name;
		namepair[name] = i;
	}
	for (int i = 0; i < n; i++)
	{
		fin >> name;
		fin >> money >> num;
		if (num != 0)
			wallet[namepair[name]] -= (money - money % num);
		for (int j = 0; j < num && num != 0; j++)
		{
			fin >> name;
			wallet[namepair[name]] += money / num;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (map<string, int> ::iterator iter = namepair.begin(); iter != namepair.end(); iter++)
		{
			if (i == iter->second)
			{
				fout << iter->first << ' ' << wallet[iter->second] << endl;
				break;
			}
		}
	}
	//system("pause");
	return 0;
}
