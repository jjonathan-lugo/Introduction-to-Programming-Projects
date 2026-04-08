#include "library.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream infile1;
ifstream infile2;

void print_states(int x, int y)
{
	if (x != -1)
	{
		move_to(x, y);
		note_position();
	}
}

void file1()
{
	infile1.open("USAMap.txt");
	if (infile1.fail())
	{
		cout << "Can't open file1" << '\n';
		exit(1);
	}
	double lon, lat;
	int min_lon = 67000;
	int max_lon = 124666;
	int min_lat = 25166;
	int max_lat = 49333;
	string state_abv;
	string test;
	infile1 >> state_abv;
	while (infile1 >> lon >> lat)
	{

		if (infile1.fail())
		{
			break;
		}
		draw_shape();
		print_states(max_lon / 60 - lon / 60 + 20, min_lon / 60 - lat / 60 - 220);
	}
}

void main()
{
	make_window(2560, 1664);
	file1();
}
