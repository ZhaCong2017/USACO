/*
ID:chac161
TASK:runround
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>
using namespace std;
int num[10];
int digit[10];
bool visit[10];

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

bool roundnum(long long x)
{
	memset(num, 0, sizeof(num));
	memset(digit, 0, sizeof(digit));
	memset(visit, false, sizeof(visit));

	long long tmp = x;
	int t = 0;
	while (tmp)
	{
		digit[t] = tmp % 10;
		t++;
		num[tmp % 10]++;
		tmp /= 10;
	}
	for (int i = 0, j = t - 1; i < j; i++, j--)
		swap(digit[i], digit[j]);

	if (num[0] > 0)
		return false;
	for (int i = 1; i < 10; i++)
	{
		if (num[i] > 1)
			return false;
	}

	int place = 0;
	visit[place] = true;
	for (int i = 0; i < t - 1; i++)
	{
		place = (place + digit[place]) % t;
		if (visit[place] == true)
			return false;
		visit[place] = true;
	}
	if ((place + digit[place]) % t == 0)
		return true;
	else
		return false;
}

int main()
{
	ifstream fin("runround.in");
	ofstream fout("runround.out");
	int n;
	fin >> n;
	for (long long i = n + 1;; i++)
	{
		if (roundnum(i))
		{
			fout << i << endl;
			break;
		}
	}

	//system("pasue");
	return 0;
}
