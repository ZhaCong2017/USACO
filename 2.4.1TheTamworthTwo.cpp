/*
ID:chac161
TASK:ttwo
LANG:C++
*/

#include<iostream>
#include<fstream>
using namespace std;
struct position
{
	int x, y;
	int direction[2];
};

char map[10][10];
position *farmerstart, *cowstart;

position *newposition(int i, int j)
{
	position *tmp = new position();
	tmp->x = i;
	tmp->y = j;
	tmp->direction[0] = 0;
	tmp->direction[1] = -1;
	return tmp;
}

void turn(position *now)
{
	int dirc = now->direction[0] * 10 + now->direction[1];
	switch (dirc)
	{
	case 1:
		now->direction[0] = -1;
		now->direction[1] = 0;
		break;
	case -1:
		now->direction[0] = 1;
		now->direction[1] = 0;
		break;
	case 10:
		now->direction[0] = 0;
		now->direction[1] = 1;
		break;
	case -10:
		now->direction[0] = 0;
		now->direction[1] = -1;
		break;
	}

}

void move(position *now)
{
	int x = now->x + now->direction[0];
	int y = now->y + now->direction[1];
	if (map[y][x] != '*' && x >= 0 && x < 10 && y >= 0 && y < 10)
	{
		now->x += now->direction[0];
		now->y += now->direction[1];
	}
	else
		turn(now);
}

bool sameplace(position *farmer, position *cow)
{
	if (farmer->x == cow->x && farmer->y == cow->y)
		return true;
	else
		return false;
}

bool circle(position *farmer, position *cow)
{
	if (sameplace(farmer, farmerstart) && sameplace(cow, cowstart))
		return true;
	else
		return false;
}

int main()
{
	ifstream fin("ttwo.in");
	ofstream fout("ttwo.out");
	position *farmer = new position(); 
	position *cow = new position();
	farmerstart = cowstart = new position();
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			fin >> map[i][j];
			if (map[i][j] == 'F')
			{
				farmer = newposition(j, i);
				farmerstart = newposition(j, i);
			}
			else if (map[i][j] == 'C')
			{
				cow = newposition(j, i);
				cowstart = newposition(j, i);
			}
		}
	}
	
	int t = 0;
	while (1)
	{
		move(farmer);
		move(cow);
		t++;
		if (sameplace(farmer, cow))
		{
			fout << t << endl;
			break;
		}
		if ((t > 4 && circle(farmer, cow)) || t > 100000)
		{
			fout << 0 << endl;
			break;
		}
	}
	//system("pasue");
	return 0;
}
