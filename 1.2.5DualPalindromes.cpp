/*
ID:chac161
TASK:dualpal
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

char num[15] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

string convertion(int x, int n)
{
	string result = "";
	while (x)
	{
		result += num[x % n];
		x /= n;
	}
	reverse(result.begin(), result.end());
	return result;
}

bool ispalindrome(string s)
{
	int i = 0, j = s.length() - 1;
	while (i < j)
	{
		if (s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

bool match(int x)
{
	int t = 0;
	for (int j = 2; j <= 10; j++)
	{
		if (ispalindrome(convertion(x, j)))
			t++;
		if (t >= 2)
			return true;
	}
	return false;
}
int main()
{
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	int n, s;
	int num = 0;
	fin >> n >> s;
	int t = 0;
	for (int i = s + 1; ; i++)
	{
		if (match(i))
		{
			fout << i << endl;
			t++;
		}
		if (t == n)
			break;
	}
	//system("pause");
	return 0;
}
