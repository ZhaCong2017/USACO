/*
ID:chac161
TASK:palsquare
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

char num[20] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K' };

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

int main()
{
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	int n;
	fin >> n;
	string quare;
	for (int i = 1; i <= 300; i++)
	{
		quare = convertion(i * i, n);
		if (ispalindrome(quare))
			fout << convertion(i, n) << ' ' << quare << endl;
	}
	//system("pause");
	return 0;
}
