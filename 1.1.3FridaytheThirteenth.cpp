/*
ID:chac161
TASK:friday
LANG:C++
*/

#include<iostream>
#include<fstream>
using namespace std;

bool leapyear(int x)
{
	if (x % 4 != 0)
		return false;
	else if (x % 400 == 0)
		return true;
	else if (x % 100 == 0)
		return false;
	else
		return true;
}

int main()
{
	ifstream fin("friday.in");
	ofstream fout("friday.out");
	int n;
	fin >> n;
	int *num = new int[7]();
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = 2;
	for (int i = 0; i < n; i++)
	{
		bool leap = leapyear(1900 + i);
		for (int j = 0; j < 12; j++)
		{
			num[(day + 12) % 7]++;
			day = (day + month[j]) % 7;
			if (j == 1 && leap)
				day++;
		}
	}
	for (int i = 0; i < 6; i++)
		fout << num[i] << ' ';
	fout << num[6] << endl;
	//system("pause");
	return 0;
}
