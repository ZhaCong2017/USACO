/*
ID:chac161
TASK:holstein
LANG:C++
*/

#include<iostream>
#include<fstream>
using namespace std;
int num, n, *vitamins, **feed;
int result = 2000, *rec;


void dfs(int now, int *recipe)
{
	if (now > num)
		return;
	int *v = new int[num]();
	for (int i = 1; i <= now; i++)
	{
		for (int j = 0; j < num; j++)
			v[j] += feed[recipe[i]][j];
	}
	bool find = true;
	for (int i = 0; i < num; i++)
	{
		if (v[i] < vitamins[i])
		{
			find = false;
			break;
		}
	}
	if (find && now < result)
	{
		result = now;
		for (int i = 0; i < result; i++)
			rec[i] = recipe[i + 1];
		return;
	}
	now++;
	for (int i = recipe[now - 1] + 1; i < n; i++)
	{
		recipe[now] = i;
		dfs(now, recipe);
		recipe[now] = -1;
	}
}


int main()
{
	ifstream fin("holstein.in");
	ofstream fout("holstein.out");
	fin >> num;
	vitamins = new int[num + 5];
	feed = new int*[num + 5];
	rec = new int[num + 5];
	for (int i = 0; i < num; i++)
		fin >> vitamins[i];
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		feed[i] = new int[num];
		for (int j = 0; j < num; j++)
			fin >> feed[i][j];
	}
	int *recipe = new int[num + 5];
	for (int i = 0; i < num + 5; i++)
		recipe[i] = -1;
	dfs(0, recipe);

	fout << result;
	for (int i = 0; i < result; i++)
		fout << ' ' << rec[i] + 1;
	fout << endl;
	//system("pause");
	return 0;
}
