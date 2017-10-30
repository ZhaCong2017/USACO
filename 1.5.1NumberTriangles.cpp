/*
ID:chac161
TASK:numtri
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main()
{
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");
	int n;
	fin >> n;
	int **num = new int*[n];
	int**result = new int*[n];
	for (int i = 0; i < n; i++)
	{
		num[i] = new int[n];
		result[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			fin >> num[i][j];
	}
	result[0][0] = num[0][0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				result[i][j] = result[i - 1][j] + num[i][j];
			else
				result[i][j] = max(result[i - 1][j] + num[i][j], result[i - 1][j - 1] + num[i][j]);
		}
	}
	int maximun = 0;
	for (int i = 0; i < n; i++)
	{
		maximun = maximun > result[n - 1][i] ? maximun : result[n - 1][i];
	}
	fout << maximun << endl;
	//system("pause");
	return 0;
}
