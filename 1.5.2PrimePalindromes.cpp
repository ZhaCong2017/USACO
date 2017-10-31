/*
ID:chac161
TASK:pprime
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
using namespace std;

string inttostring(int x)
{
	string result;
	while (x)
	{
		result += (x % 10 + '0');
		x /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}

bool ispalindromes(string s)
{
	for (int i = 0, j = s.length() - 1; i < j; i++, j--)
	{
		if (s[i] != s[j])
			return false;
	}
	return true;
}

int main()
{
	ifstream fin("pprime.in");
	ofstream fout("pprime.out");
	int a, b;
	fin >> a >> b;
	if (b > 10000000)
		b = 10000000;

	bool *prime = new bool[b + 1];
	for (int i = 0; i <= b; i++)
		prime[i] = true;
	for (int i = 2; i <= b; i++)
	{
		if (prime[i])
		{
			for (int j = 2; i * j <= b; j++)
				prime[i * j] = false;
		}
	}

	string s;
	for(int i = a; i <= b; i++)
	{
		if (prime[i])
		{
			s = inttostring(i);
			if (ispalindromes(s))
				fout << i << endl; 
		}
	}

	//system("pause");
	return 0;
}
