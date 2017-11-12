/*
ID:chac161
TASK:fact4
LANG:C++
*/

#include<iostream>
#include<fstream>
using namespace std;
#define MAX 1000000000

int main()
{
	ifstream fin("fact4.in");
	ofstream fout("fact4.out");
	int n;
	fin >> n;
	long long factorial = 1;
	for (int i = 1; i <= n; i++)
	{
		factorial *= i;
		while (factorial % 10 == 0)
			factorial /= 10;
		while (factorial > MAX)
			factorial %= MAX;
	}

	fout << factorial % 10 << endl;
	//system("pasue");
	return 0;
}
