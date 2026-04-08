#include "library.h" 

void draw_star(const int x, const int y, const int length) 
{
	set_pen_color(color::black); 
	set_pen_width(3); 
	move_to(x,y); 
	set_heading_degrees(90); 
	draw_distance(length); 
	turn_left_by_degrees(180-108); 
	draw_distance(length); 
	turn_right_by_degrees(180-36); 
	draw_distance(length); 
	turn_left_by_degrees(180-108); 
	draw_distance(length); 
	turn_right_by_degrees(180-36); 
	draw_distance(length); 
	turn_left_by_degrees(180-108); 
	draw_distance(length); 
	turn_right_by_degrees(180-36); 
	draw_distance(length); 
	turn_left_by_degrees(180-108); 
	draw_distance(length); 
	turn_right_by_degrees(180-36); 
	draw_distance(length); 
	turn_left_by_degrees(180-108); 
	draw_distance(length); 
	turn_right_by_degrees(180-36); 
	draw_distance(length); 
}

void main() 
{ 
	make_window(400, 400); 
	draw_star(50, 150, 50);  
}
