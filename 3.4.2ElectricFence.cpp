/*
ID:chac161
TASK:fence9
LANG:C++
*/

#include <iostream>
#include<fstream>
using namespace std;
#define E 0.00001
double m, n, p;

int main()
{
	ifstream fin("fence9.in");
	ofstream fout("fence9.out");
	fin >> n >> m >> p;

	int result = 0;
	for (int i = 1; i < m; i++)
	{
		int x1, x2;
		x1 = i * n / m + E;
		x2 = (n - p) * i / m + p - E;
		result += (x2 - x1 + E);
	}
	fout << result << endl;
	//system("pause");
	return 0;
}
