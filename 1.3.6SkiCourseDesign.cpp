/*
ID:chac161
TASK:skidesign
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<map>
#include<math.h>
using namespace std;
#define INT_MAX 2147483647;

int n, *height;

int cost(int h)
{
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		if (height[i] > h + 8)
			result += (height[i] - h - 8) * (height[i] - h - 8);
		if (height[i] < h - 9)
			result += (height[i] - h + 9) * (height[i] - h + 9);
	}
	return result;
}
int main()
{
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");
	fin >> n;
	height = new int[n];
	for (int i = 0; i < n; i++)
		fin >> height[i];
	int result = INT_MAX;
	int now;
	for (int i = 1; i <= 100; i++)
	{
		now = cost(i);
		if (result > now)
			result = now;
	}
	fout << result << endl;
	//system("pause");
	return 0;
}
