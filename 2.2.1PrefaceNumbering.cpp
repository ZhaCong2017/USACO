/*
ID:chac161
TASK:preface
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<map>
using namespace std;
map<char, int> result;
int num_list[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
string name_list[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

void ArabiatoRome(int x)
{
	string tmp;
	for (int i = 0; i < 13; i++)
	{
		while (x >= num_list[i])
		{
			x -= num_list[i];
			tmp += name_list[i];
		}
	}
	for (int i = 0; i < tmp.length(); i++)
	{
		result[tmp[i]] += 1;
	}
}

int main()
{
	ifstream fin("preface.in");
	ofstream fout("preface.out");
	char name[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
	for (int i = 0; i < 7; i++)
		result[name[i]] = 0;
	int n;
	fin >> n;
	for (int i = 1; i <= n; i++)
	{
		ArabiatoRome(i);
	}
	int *output = new int[7]();
	for (map<char, int> ::iterator iter = result.begin(); iter != result.end(); iter++)
	{
		char tmp = iter->first;
		for (int j = 0; j < 7; j++)
		{
			if (name[j] == iter->first)
			{
				output[j] = iter->second;
				break;
			}
		}
	}

	for (int i = 0; i < 7; i++)
	{
		if (output[i] > 0)
			fout << name[i] << ' ' << output[i] << endl;
	}
	//system("pause");
	return 0;
}
