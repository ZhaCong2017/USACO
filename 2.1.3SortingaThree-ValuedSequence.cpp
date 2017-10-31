/*
ID:chac161
TASK:sort3
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");
	int n;
	fin >> n;
	vector<int> num(n);
	int *time = new int[3]();
	int exchange[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			exchange[i][j] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		fin >> num[i];
		time[num[i] - 1]++;
	}
	time[1] += time[0];
	time[2] += time[1];

	for (int i = 0; i < n; i++)
	{
		if (num[i] != 1 && i < time[0])
			exchange[0][num[i] - 1]++;
		if (num[i] != 2 && i >= time[0] && i < time[1])
			exchange[1][num[i] - 1]++;
		if (num[i] != 3 && i >= time[1] && i < time[2])
			exchange[2][num[i] - 1]++;
	}

	int result = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i != j)
			{
				int min = exchange[i][j] < exchange[j][i] ? exchange[i][j] : exchange[j][i];
				exchange[i][j] -= min;
				exchange[j][i] -= min;
				result += min;
			}
		}
	}
	result += 2 * (exchange[0][0] + exchange[0][1] + exchange[0][2]);
	fout << result << endl;

	//system("pause");
	return 0;
}
