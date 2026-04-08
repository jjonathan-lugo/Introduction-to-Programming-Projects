 #include "library.h"

void draw_star(int x, int y, int length)
{
	set_pen_color(color::blue);
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
	draw_star(-5, 150, 50);
	draw_star(120, 150, 50);
	draw_star(250, 150, 50);
	//(x, y, size)
}
