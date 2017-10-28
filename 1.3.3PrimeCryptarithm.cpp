/*
ID:chac161
TASK:crypt1
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<map>
#include<algorithm>
using namespace std;

ifstream fin("crypt1.in");
ofstream fout("crypt1.out");
bool innum[10];
int *number;
int n;
int result = 0;

bool isinnum(int x)
{
	int now;
	while (x)
	{
		now = x % 10;
		if (!innum[now])
			return false;
		x /= 10;
	}
	return true;
}

bool iscryptarithm(int *formula)
{
	int a = formula[0] * 100 + formula[1] * 10 + formula[2];
	int b = formula[3] * 10 + formula[4];
	int x = a * b;
	int y = a * formula[3];
	int z = a * formula[4];
	if (isinnum(x) && isinnum(y) && isinnum(z) && x > 1000 && x < 10000 && y < 1000 && z < 1000)
		return true;
	else
		return false; 
}

void buildcryptarithm(int now, int *formula)
{
	for (int i = 0; i < n; i++)
	{
		formula[now] = number[i];
		if (now < 4)
			buildcryptarithm(now + 1, formula);
		else
		{
			if (iscryptarithm(formula))
			{
				result++;
				continue;
			}
		}
	}
}

int main()
{
	fin >> n;
	number = new int[n];
	for (int i = 0; i < 10; i++)
		innum[i] = false;
	int formula[5];
	int tmp;
	for (int i = 0; i < n; i++)
	{
		fin >> number[i];
		innum[number[i]] = true;
	}
	buildcryptarithm(0, formula);
	fout << result << endl;

	//system("pause");
	return 0;
}
