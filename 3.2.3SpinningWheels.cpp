/*
ID:chac161
TASK:spin
LANG:C++
*/

#include <iostream>
#include<fstream>
using namespace std;
int v[5], w[5], start[5][8], ended[5][8];
int t;

void move()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < w[i]; j++)
		{
			start[i][j] = (start[i][j] + v[i]) % 360;
			ended[i][j] = (ended[i][j] + v[i]) % 360;
		}
	}
}

bool isgap(int x)
{
	for (int i = 0; i < 5; i++)
	{
		bool is = false;
		for (int j = 0; j < w[i]; j++)
		{
			if (start[i][j] <= ended[i][j] && start[i][j] <= x && ended[i][j] >= x)
			{
				is = true;
				break;
			}
			else if (start[i][j] > ended[i][j] && (start[i][j] <= x || ended[i][j] >= x))
			{
				is = true;
				break;
			}
		}
		if (!is)
			return false;
	}
	return true;
}

int main()
{
	ifstream fin("spin.in");
	ofstream fout("spin.out");
	for (int i = 0; i < 5; i++)
	{
		fin >> v[i] >> w[i];
		for (int j = 0; j < w[i]; j++)
		{
			fin >> start[i][j] >> ended[i][j];
			ended[i][j] += start[i][j];
		}

	}
	for (t = 1;; t++)
	{
		int first = v[0] * t % 360;
		bool is = true;
		for (int j = 1; j < 5; j++)
		{
			if (t * v[j] % 360 != first)
			{
				is = false;
				break;
			}
		}
		if (is)
			break;
	}
	int i;
	bool is;
	for (i = 0; i <= t; i++)
	{
		is = false;
		for (int j = 0; j < 360; j++)
		{
			if (isgap(j))
			{
				is = true;
				break;
			}
		}
		if (is)
			break;
		move();
	}
	if (is)
		fout << i << endl;
	else
		fout << "none" << endl;
	//system("pause");
	return 0;
}
