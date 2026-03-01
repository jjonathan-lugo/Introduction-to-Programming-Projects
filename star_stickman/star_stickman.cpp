//A.	How Long is a Year?
#include "library.h"

int yearfunction(int sec, int min, int hr, int d)
{
	int answer = (sec * min * hr * d);
		return (answer);
}

void main()
{
	print(yearfunction(365, 24, 60, 60));
}

//B.	Black Magic, Star
#include "library.h"

void main()
{
	make_window(400, 400);
	set_pen_color(color::red);
	set_pen_width(5);
	move_to(150, 250);
	turn_right_by_degrees(18);
	draw_distance(100);
	turn_right_by_degrees(144);
	draw_distance(100);
	turn_right_by_degrees(144);
	draw_distance(100);
	turn_right_by_degrees(144);
	draw_distance(100);
	turn_right_by_degrees(144);
	draw_distance(100);
//Title
	move_to(150, 290);
	set_pen_color(color::black);
	set_font_size(40);
	write_string("Star");
}

//C.	Stick Men, Round Heads
 #include "library.h"

void main()
{
//Head
	make_window(400, 400);
	set_pen_color(color::black);
	set_pen_width(100);
	move_to(200,90);
	draw_distance(1);
	set_pen_color(color::white);
	set_pen_width(90);
	draw_distance(1);
//Eyes
	set_pen_color(color::black);
	set_pen_width(10);
	move_to(180, 80);
	draw_distance(1);
	set_pen_color(color::black);
	set_pen_width(10);
	move_to(220, 80);
	draw_distance(1);
//Mouth
	set_pen_color(color::black);
	set_pen_width(5);
	move_to(180, 110);
	turn_right_by_degrees(90);
	draw_distance(40);
//Neck/Torso
	set_pen_color(color::black);
	set_pen_width(7);
	move_to(200, 140);
	turn_right_by_degrees(90);
	draw_distance(150);
//Legs
	set_pen_color(color::black);
	set_pen_width(7);
	move_to(200, 290);
	turn_right_by_degrees(30);
	draw_distance(100);
	set_pen_color(color::black);
	set_pen_width(7);
	move_to(200, 290);
	turn_right_by_degrees(300);
	draw_distance(100);
//Arms
	set_pen_color(color::black);
	set_pen_width(7);
	move_to(200, 190);
	turn_right_by_degrees(100);
	draw_distance(100);
	set_pen_color(color::black);
	set_pen_width(7);
	move_to(200, 190);
	turn_right_by_degrees(160);
	draw_distance(100);
//Title
	move_to(130, 30);
	set_pen_color(color::red);
	set_font_size(40);
	write_string("Stick Man");
}
