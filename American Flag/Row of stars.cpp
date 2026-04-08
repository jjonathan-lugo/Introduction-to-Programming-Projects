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

void row_of_six_stars(int x, int y, int length)
{
//Row 1
	draw_star(x , y, length);
	draw_star(x + 40, y, length);
	draw_star(x + 80, y, length);
	draw_star(x + 120, y, length);
	draw_star(x + 165, y, length);
	draw_star(x + 205, y, length);
}

void row_of_five_stars(int x, int y, int length)
{
//Row 2
	draw_star(x + 5, y + 5, length);
	draw_star(x + 45, y + 5, length);
	draw_star(x + 85, y + 5, length);
	draw_star(x + 127,y + 5, length);
	draw_star(x + 170,y + 5, length);
}


void main()
{
//Flag Background
	make_window(760, 400);
	//(x, y, size)
	set_pen_color(color::blue);
	fill_rectangle(250, 0, -400, 210);
	//(x, y, moves the color right and left, shrinks color up, and down)
	//4
	
//Star
	row_of_six_stars(15, 15, 8);
	row_of_five_stars(30, 30, 8);
}
