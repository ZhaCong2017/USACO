/*
ID:chac161
TASK:milk
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	ifstream fin("milk.in");
	ofstream fout("milk.out");
	int total, n;
	fin >> total >> n;
	map<int, int> price;
	int p, num;
	for (int i = 0; i < n; i++)
	{
		fin >> p >> num;
		if (price.find(p) == price.end())
			price[p] = num;
		else
			price[p] = price[p] + num;
	}
	int result = 0;
	map<int, int> ::iterator iter = price.begin();
	while (total > 0)
	{
		if (total < iter->second)
			result += total * iter->first;
		else		
			result += iter->first * iter->second;
		total -= iter->second;
		iter++;
	}
	fout << result << endl;
	//system("pause");
	return 0;
}
