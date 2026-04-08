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
	infile1 >> state_abv;
	start_shape(); //tell new shape
	while (true)
	{
		infile1 >> lon >> lat; //if at end exit
		if (infile1.fail())
		{
			break;
		}
		if (lon < 0) //check if end at state
		{
			draw_shape();
			infile1 >> state_abv;
			start_shape();
			continue;
		}
		cout << max_lon / 60 - lon / 60 + 20 << min_lon / 60 - lat / 60 - 220 << '\n';
		print_states(max_lon / 60 - lon / 60 + 20, min_lon / 60 - lat / 60 - 220);
	}
}

void draw_star(int x, int y, string abv)
{
	set_pen_color(color::red);
	set_pen_width(5);
	move_to(x, y);
	turn_right_by_degrees(18);
	draw_distance(10);
	turn_right_by_degrees(144);
	draw_distance(10);
	turn_right_by_degrees(144);
	draw_distance(10);
	turn_right_by_degrees(144);
	draw_distance(10);
	turn_right_by_degrees(144);
	draw_distance(10);
	//Title
	move_to(x, y);
	set_pen_color(color::black);
	set_font_size(12);
	write_string(abv);

}

void file2()
{
	infile2.open("MappCOor.txt");
	if (infile2.fail())
	{
		cout << "Can't open file1" << '\n';
		exit(1);
	}
	double lat, lon;
	int min_lon = 67000;
	int max_lon = 124666;
	int min_lat = 25166;
	int max_lat = 49333;
	int pos_x;
	int pos_y;
	string abv, state_name;
	while (true)
	{
		infile2 >> abv >> state_name >> lat >> lon;
		if (infile2.fail())
		{
			break;
		}
		pos_x = (2560 - lon*33) / 2 + 800;
		pos_y =  (1664 - lat*33) / 2 + 60;
		draw_star(pos_x, pos_y, abv);
		cout << abv << state_name << lat << lon << '\n';
		cout << pos_x << " " << pos_y << '\n';
	}
}

void main()
{
	make_window(2560, 1664);
	file1();
	file2();
}
