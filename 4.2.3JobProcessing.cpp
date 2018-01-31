/*
ID:chac161
TASK:job
LANG:C++
*/

#include <iostream>
#include<fstream>
using namespace std;
#define MAX 1000000

int n, m1, m2, tmp, k;
int A[35], B[35];
int timeA[35], timeB[35];
int task1[1010], task2[1010];


int main()
{
	ifstream fin("job.in");
	ofstream fout("job.out");
	fin >> n >> m1 >> m2;
	int result = 0;
	for (int i = 0; i < m1; i++)
		fin >> A[i];
	for (int i = 0; i < m2; i++)
		fin >> B[i];
	for (int i = 0; i < n; i++)
	{
		tmp = MAX;
		for (int j = 0; j < m1; j++)
		{
			if (tmp > timeA[j] + A[j])
			{
				tmp = timeA[j] + A[j];
				k = j;
			}
		}
		task1[i] = timeA[k] = tmp;
	}
	
	for (int i = 0; i < n; i++)
	{
		tmp = MAX;
		for (int j = 0; j < m2; j++)
		{
			if (tmp > timeB[j] + B[j])
			{
				tmp = timeB[j] + B[j];
				k = j;
			}
		}
		task2[i] = timeB[k] = tmp;
	}
	int ans1, ans2;
	ans1 = ans2 = 0;
	for (int i = 0; i < n; i++)
	{
		ans1 = ans1 > task1[i] ? ans1 : task1[i];
		ans2 = ans2 > (task1[i] + task2[n - i - 1]) ? ans2 : (task1[i] + task2[n - i - 1]);
	}
	fout << ans1 << " " << ans2 << endl;
	//system("pause");
	return 0;
}
