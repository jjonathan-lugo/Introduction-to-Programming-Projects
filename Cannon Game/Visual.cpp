#include "library.h"


double const g = 32.174; 

double height(double const v, double const t)
{
	double const h = (v * t) - (0.5 * g * (t * t));
	return(h);
}

double air_time(double const v, double const theta)
{
	double const air_time = 2 * v * sin(theta) / g;
	return air_time;
}

void tabulation(double const v, double const t, double const theta, double const red, double const blue)
{

	if (t <= air_time(v,theta)) 
	{
		print(" After");
		print(" ");
		print(t);
		print(" seconds, height is ");
		print(height(v, t)); 
		print(" feet");
		set_pen_color(red , 0.0, blue);
		set_pen_width(10);
		draw_point(200.0, height(v,t));
		new_line();
		wait(0.35);
		tabulation(v, t + 1, theta, red - 0.2, blue + 0.3);
	}
}

void user_ask_velocity() 
{
	print("TYpe Velocity: ");
	double velocity = read_double();
	print("Type Cannon Degree: ");
	double theta = read_double() * 0.0174;
	tabulation(velocity, 0, theta, 1, 0);

}

void main()
{
	make_window(400, 400);
	user_ask_velocity();
}
