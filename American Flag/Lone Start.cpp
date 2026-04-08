#include "library.h" 

void draw_star(int x, int y, int length)
{
	set_pen_color(color::white);
	start_shape();
	set_pen_width(3);
	move_to(x, y);
	note_position();
	set_heading_degrees(90);
	draw_distance(length);
	note_position();
	turn_left_by_degrees(180 - 108);
	draw_distance(length);
	note_position();
	turn_right_by_degrees(180 - 36);
	draw_distance(length);
	note_position();
	turn_left_by_degrees(180 - 108);
	draw_distance(length);
	note_position();
	turn_right_by_degrees(180 - 36);
	draw_distance(length);
	note_position();
	turn_left_by_degrees(180 - 108);
	draw_distance(length);
	note_position();
	turn_right_by_degrees(180 - 36);
	draw_distance(length);
	note_position();
	turn_left_by_degrees(180 - 108);
	draw_distance(length);
	note_position();
	turn_right_by_degrees(180 - 36);
	draw_distance(length);
	note_position();
	turn_left_by_degrees(180 - 108);
	draw_distance(length);
	note_position();
	turn_right_by_degrees(180 - 36);
	draw_distance(length);
	note_position();
	fill_shape();
}

void main()
{
	make_window(400, 400);
	//(x, y, size)
	set_pen_color(color::blue);
	fill_rectangle(200, 0, -200, 410);
	//(x, y, moves the color right and left, shrinks color up, and down)
	set_pen_color(color::white);
	fill_rectangle(200, 0, 210, 200);
	//(x, y, moves the color right and left, shrinks color up and down)
	set_pen_color(color::red);
	fill_rectangle(200, 200, 210, 210);
	//(x, y, moves the color right and left, shrinks color up and down)
	draw_star(20, 190, 60);
}
