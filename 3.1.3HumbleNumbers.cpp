/*
ID:chac161
TASK:humble
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<set>
using namespace std;

int main()
{
	ifstream fin("humble.in");
	ofstream fout("humble.out");
	long long k, n;
	set<long long> humble;
	fin >> k >> n;
	long long *num = new long long[k];
	long long resultnum = 0, result;
	for (long long i = 0; i < k; i++)
	{
		fin >> num[i];
		humble.insert(num[i]);
	}
	while (resultnum < n)
	{
		resultnum++;
		set<long long> ::iterator iter = humble.begin();
		long long now = *iter;
		result = now;
		humble.erase(iter);
		for (long long i = 0; i < k; i++)
		{
			if (resultnum + humble.size() < n + 5 || now * num[i] < *(--humble.end()))
				humble.insert(now * num[i]);
		}
		while (humble.size() > n + 5 - resultnum)
			humble.erase(--humble.end());
	}
	fout << result << endl;

	//system("pasue");
	return 0;
}
