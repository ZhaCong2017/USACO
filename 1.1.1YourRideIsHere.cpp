/*
ID:chac161
TASK:ride
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	string a, b;
	fin >> a >> b;
	int hash_a = 1;
	int hash_b = 1;
	for (int i = 0; i < a.length(); i++)
		hash_a = hash_a * (a[i] - 'A' + 1) % 47;
	for (int i = 0; i < b.length(); i++)
		hash_b = hash_b * (b[i] - 'A' + 1) % 47;
	if (hash_a == hash_b)
		fout << "GO" << endl;
	else
		fout << "STAY" << endl;
	//system("pause");
	return 0;
}
