#include "library.h"

double const g = 32.174;
double const pi = acos(-1.0);
int const window_height = 500;
int const window_width = 1000;
double velocity = 0;
double theta = 0;
int start_posx = 0;
int start_posy = 0;


void check_hit(double const x) //Own function 
{
	move_to(150, 290);
	set_pen_color(color::black);
	set_font_size(40);
	if (x > 500 && x < 950) //House should be between them
	{
		write_string("Hit");

	}
	else
	{
		write_string("Miss");
	}
}

double distance_forward(double const v, double const t)
{
	return v * t + start_posx;
}

double height(double const v, double const t)
{
	double const h = (v * t) - (0.5 * g * (t * t));
	return h;
}

double adj_height(double const v, double const t, double const theta)
{
	double const adj_height = v * t * cos(theta) - 0.5 * g * (t * t);
	return adj_height + start_posy;
}


double actual_height(double const v, double const t, double const theta)
{
	return window_height - adj_height(v, t, theta);
}

double air_time(double const v, double const theta)
{
	double const air_time = 2 * v * sin(theta) / g;
	return air_time;
}

double tabulation(double const v, double const t, double const theta, double const red, double const blue)
{

	//if (t <= air_time(v,theta)) 
	//{
	double dist = distance_forward(v, t);
	double ht = adj_height(v, t, theta);
	if (ht < 0) //if line goes under 0 it will stop
		return dist;
	double actual_ht = actual_height(v, t, theta);
	print(" After");
	print(" ");
	print(t);
	print(" seconds, height is ");
	print(ht);
	print(" feet.");
	cout << " (x,y) = (" << dist << ", " << actual_ht << ")";
	set_pen_color(red, 0.0, blue);
	set_pen_width(5);
	draw_to(dist, actual_ht);
	new_line();
	//wait(0.35);
	return tabulation(v, t + 0.05, theta, red - 0.002, blue + 0.004); //create arc
	//}
}

void user_ask_velocity()
{
	print("TYpe Velocity: ");
	velocity = read_double();
	print("Type Cannon Degree: ");
	theta = read_double() * 0.0174;
	move_to(0 + start_posx, window_height - start_posy); //move out & once cannon drawn at end of draw cannon add move too at end of draw cannon function 
}

void draw_cannon(double xg, double yg, double r, double L1, double L2, double w1, double w2, double a)
{
	double xc = xg;
	double yc = yg - r;
	double b = asin((w1 - w2) / 2 / (L1 + L2));
	double c = a * 0.0174 + b;
	print(c);
	print(b);
	double xp = xc - L1 * sin(a - b);
	double yp = yc + L1 * cos(a - b);
	double len = (L1 + L2) * cos(b);


	//plot point 
	//draw crcle
	//create cannon following center of circle

	start_shape();
	set_pen_width(5);
	move_to(xp, yp);
	note_position();
	set_heading_degrees(90);
	turn_left_by_radians(b); //adds angle
	draw_distance(L1 + L2); //draw line
	note_position();
	set_heading_degrees(0);
	draw_distance(w2);
	note_position();
	set_heading_degrees(270);
	turn_right_by_radians(b);
	draw_distance(L1 + L2);
	note_position();
	set_heading_degrees(180);
	draw_distance(w1);
	note_position();
	fill_shape(color::grey);

	set_pen_width(2 * r);
	set_pen_color(color::brown);
	move_to(xc, yc);
	draw_point(xc + 45, yc + 35);
	set_pen_color(color::black);
}

void random_house(int x_start, int x_finish, int house_width)
{
	int starting_point = random_in_range(x_start, x_finish - house_width);
	int xpos = starting_point;
	int ypos = 500;


	set_pen_color(color::black);

	//Base
	set_pen_width(3);
	move_to(xpos, ypos);
	set_heading_degrees(0);
	draw_distance(80);
	xpos = xpos - 80;
	move_to(xpos, ypos);
	draw_distance(80);
	
	xpos = xpos;
	move_to(xpos, ypos);
	turn_right_by_degrees(90);
	draw_distance(80);
	
	ypos = ypos - 80;
	move_to(xpos, ypos);
	draw_distance(80);

	//Door
	set_pen_width(3);
	xpos = xpos + 10;
	ypos = ypos + 20;
	move_to(xpos, ypos);
	turn_right_by_degrees(90);
	draw_distance(60);
	set_pen_width(3);
	xpos = xpos + 20;
	move_to(xpos, ypos);
	draw_distance(60);
	set_pen_width(3);
	move_to(xpos, ypos);
	turn_right_by_degrees(90);
	draw_distance(20);

	////Window
	set_pen_width(3);
	xpos = xpos + 40;
	ypos = ypos + 25;
	move_to(xpos, ypos);
	turn_right_by_degrees(90);
	draw_distance(25);
	set_pen_width(3);
	xpos = xpos - 20;
	move_to(xpos, ypos);
	draw_distance(25);
	set_pen_width(3);
	move_to(xpos, ypos);
	turn_right_by_degrees(90);
	draw_distance(20);
	set_pen_width(3);
	ypos = ypos - 25;
	move_to(xpos, ypos);
	draw_distance(20);

	//Roof
	set_pen_width(3);
	xpos = xpos - 12;
	ypos = ypos - 62;
	move_to(xpos, ypos);
	turn_right_by_degrees(45);
	draw_distance(60);
	set_pen_width(3);
	move_to(xpos, ypos);
	turn_right_by_degrees(88);
	draw_distance(56);
}

void main()
{	//4 Attemps
	make_window(window_width, window_height);
	start_posx = 160; //move before move_to in the cannon function 
	start_posy = 55;
	user_ask_velocity();
	double x = tabulation(velocity, 0, theta, 1, 0);
	check_hit(x);
	draw_cannon(10, 460, 30, 50, 100, 50, 40, 0); //use user give
	random_house(500, 950, 80);
	make_window(window_width, window_height);
	start_posx = 160; //move before move_to in the cannon function 
	start_posy = 55;
	user_ask_velocity();
	double x = tabulation(velocity, 0, theta, 1, 0);
	check_hit(x);
	draw_cannon(10, 460, 30, 50, 100, 50, 40, 0); //use user give
	random_house(500, 950, 80);
	make_window(window_width, window_height);
	start_posx = 160; //move before move_to in the cannon function 
	start_posy = 55;
	user_ask_velocity();
	double x = tabulation(velocity, 0, theta, 1, 0);
	check_hit(x);
	draw_cannon(10, 460, 30, 50, 100, 50, 40, 0); //use user give
	random_house(500, 950, 80);
	make_window(window_width, window_height);
	start_posx = 160; //move before move_to in the cannon function 
	start_posy = 55;
	user_ask_velocity();
	double x = tabulation(velocity, 0, theta, 1, 0);
	check_hit(x);
	draw_cannon(10, 460, 30, 50, 100, 50, 40, 0); //use user give
	random_house(500, 950, 80);

	
}
