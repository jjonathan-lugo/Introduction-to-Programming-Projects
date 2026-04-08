#include "library.h"

double const g = 32.174; //gravitational force slowing down objects motion 

//Notes
	//when const is used it restrict the value preventing it from ever changing

//Formula of height of object after being launched (cannon shot)
//Formula h = vt - 1/2gt^2
double height(double const v, double const t)
{
	double const h = (v * t) - (0.5 * g * (t * t));
	return(h);
}

void main() //Used to test my formula 
{
	double v = 50.0;  // Initial velocity in ft/s
	double t = 5.0;   // Time in seconds
	double h = height(v, t); //calls the height
	std::cout << "The height is: " << h << " feet" << std::endl;
	std::cout - used to display text/values
	<< takes value of right side and outputs it
	std::endl - insert newline(move cursor to next line) - writes all text immeditaly 
}

double air_time(double const v) //g isn't needed to be defined b/c it alreayd is defined
{
	double const air_time = 2 * (v / g);
	return(air_time);
}

void main() //used to test air_time formula
{
	double v = 50.0;
	double t = air_time(v);
	std::cout << "The air time is: " << t << " seconds" << std::endl;
}
