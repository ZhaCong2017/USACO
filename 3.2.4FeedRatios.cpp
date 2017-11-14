/*
ID:chac161
TASK:ratios
LANG:C++
*/

#include <iostream>
#include<fstream>
using namespace std;

int main()
{
	ifstream fin("ratios.in");
	ofstream fout("ratios.out");
	double aim[3], ratios[3][3];
	double x, y, z;
	fin >> aim[0] >> aim[1] >> aim[2];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			fin >> ratios[i][j];
	}

	int a, b, c, result = 1000;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			for (int k = 0; k < 100; k++)
			{
				if (i == 0 && j == 0 && k == 0)
					continue;
				if (result > i + j + k)
				{
					x = ratios[0][0] * i + ratios[1][0] * j + ratios[2][0] * k;
					y = ratios[0][1] * i + ratios[1][1] * j + ratios[2][1] * k;
					z = ratios[0][2] * i + ratios[1][2] * j + ratios[2][2] * k;
					if (y / x == aim[1] / aim[0] && z / x == aim[2] / aim[0]) 
					{
						if (x >= aim[0])
						{
							result = x / aim[0];
							a = i; b = j; c = k;
						}
						else
						{
							result = aim[0] / x;
							a = i * result; b = j * result; c = k * result;
							result = 1;
						}
					}
				}
			}
		}
	}
	if (result == 1000)
		fout << "NONE" << endl;
	else
		fout << a << ' ' << b << ' ' << c << ' ' << result << endl;

	//system("pause");
	return 0;
}
