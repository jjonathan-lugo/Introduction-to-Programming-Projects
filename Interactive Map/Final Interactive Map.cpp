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
	set_pen_width(1);
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

void file1_state(string input)
{
	//open file
	infile1.open("USAMap.txt");
	if (infile1.fail())
	{
		cout << "Can't open file1" << '\n';
		exit(1);
	}

	//variables
	double lon, lat;
	int min_lon = 67000;
	int max_lon = 124666;
	int min_lat = 25166;
	int max_lat = 49333;

	string state_abv;
	start_shape();
	//change pen width
	set_pen_width(1);
	while (infile1)
	{

		infile1 >> state_abv;			//read in a word
		if (state_abv == input)			//if its the state youre looking for...
		{
			//start a new loop that runs until you reach -1, -1
			while (true) {
				//read in a coordinate pair
				infile1 >> lon >> lat;
				//if its -1 -1, break out of the loop
				if (lon == -1 && lat == -1) {
					break;				
				}
				//if its not -1 -1, note the position
				print_states(max_lon / 60 - lon / 60 + 20, min_lon / 60 - lat / 60 - 220);
			}
			draw_shape();
		}
	}

	//close the file
	infile1.close();
}


void draw_star(int x, int y, string capital_name)
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
	write_string(capital_name);

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
		pos_x = (2560 - lon * 33) / 2 + 800;
		pos_y = (1664 - lat * 33) / 2 + 60;
		draw_star(pos_x, pos_y, abv);
		cout << abv << state_name << lat << lon << '\n';
		cout << pos_x << " " << pos_y << '\n';
	}
}

void file2_state(string input) {
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
	string abv, state_abv, capital_name;

	while (infile2) {
		infile2 >> state_abv;			//read in a word
		if (state_abv == input) {		//if its the state youre looking for...
			infile2 >> capital_name >> lat >> lon;
			pos_x = (2560 - lon * 33) / 2 + 800;
			pos_y = (1664 - lat * 33) / 2 + 60;
			draw_star(pos_x, pos_y, state_abv);
		}
	}
	//close the file
	infile2.close();
}

void main()
{
	make_window(2560, 1664);

	while(true) {
		string state;
		cout << "Enter a state abbreviation: ";
		cin >> state;
		if (state == "ALL") {
			clear();
			file1();
			file2();
		}
		else {
			file1_state(state);
			file2_state(state);
		}
	}
}
