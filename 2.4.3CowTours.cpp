/*
ID:chac161
TASK:cowtour
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
using namespace std;
#define MAXINT 2147483647

double getdistance(long long *a, long long *b)
{
	return sqrt((b[1] - a[1]) * (b[1] - a[1]) + (b[0] - a[0]) * (b[0] - a[0]));
}

int main()
{
	ifstream fin("cowtour.in");
	ofstream fout("cowtour.out");
	int n;
	fin >> n;
	long long **place = new long long*[n];
	int **connection = new int*[n];
	double **dis = new double*[n];
	double *maxdis = new double[n]();
	double result = MAXINT;
	char tmp[500];
	for (int i = 0; i < n; i++)
	{
		place[i] = new long long[2];
		fin >> place[i][0] >> place[i][1];
	}
	fin.getline(tmp, 500);
	for (int i = 0; i < n; i++)
	{
		dis[i] = new double[n];
		connection[i] = new int[n];
		fin.getline(tmp, 500);
		for (int j = 0; j < n; j++)
		{
			connection[i][j] = tmp[j] - '0';
			if (connection[i][j])
				dis[i][j] = getdistance(place[i], place[j]);
			else
				dis[i][j] = MAXINT;
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dis[i][j] = dis[i][k] + dis[j][k] < dis[i][j] ? dis[i][k] + dis[j][k] : dis[i][j];
			}
		}
	}
	double result1 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j && dis[i][j] < MAXINT - 1 && dis[i][j] > maxdis[i])
				maxdis[i] = dis[i][j];
		}
		if (result1 < maxdis[i])
			result1 = maxdis[i];
	}

 	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (dis[i][j] > MAXINT - 1)
			{
				double now = getdistance(place[i], place[j]) + maxdis[i] + maxdis[j];
				result = now > result ? result : now;
			}
		}
	}
	fout << fixed << setprecision(6) << (result > result1 ? result : result1) << endl;
	//system("pasue");
	return 0;
}
