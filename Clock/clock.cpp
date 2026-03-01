#include "library.h"

//Notes
//(%) w/ integer [23] if divided by a number it will only print # after the decimal [.] point
//(%)w/ double [23.78] if divided by a number it will only print # before the decimal [.] point

int year(int dd)
{
	int year = dd / 10000;
	//removes day and month
	//Ex) 20241215 (YYYYMMDD) When divided by 10,000 it moves to the left 4 time
	//creating 2024.1215 and since it is a int function 2024 would only print
	return (year);
}

int month(int dd)
{
	int monthday = dd % 10000;
	//Creates {YYYY.MMDD}. Then removes the first 4 digits from [YYYYMMDD] leaving then month/day (MMDD)
	int month = monthday / 100;
	//moved the decimal left from (MMDD) to give only the day (DD)
	return (month);
}

int day(int dd)
{
	int day = dd % 100;
	//creates {YYYYMM.DD}. Then removes the first 2 digits from (MMDD) leaving the day (DD)
	//dd & 10000 isn't needed b/c in [YYYYMMDD] the day isn't in between the year and day like months did
	return (day);
}

int hour(int tm)
{
	int hour = tm / 10000;
	if (hour <= 12)
	{
		int am = hour;
		return(am);
	}
	if (hour > 12)
	{
		int pm = hour - 12;
		return(pm);

	}
	return (hour);
}

string day_night(int tm) //string allow return of words
{
	int  hour = tm / 10000;
	if (hour < 12)
	{
		return " a.m. ";
	}
	if (hour >= 12)
	{
		return " p.m. ";
	}

}

int minute(int  tm)
{
	int  monthday = tm / 100;
	//From [MMDD.HHMMSS] to [HHMMSS] 
	int  minute = monthday % 100;
	//[HHMM.SS] to [HHMM] to [HH.MM] to [MM]
	return(minute);
}

int second(int tm)
{
	int second = tm % 100;
	return(second);
}


void clock_dial(int x, int y)
{
	//0 degrees point up, 90 degrees point right, 180 degrees points down, 270 degrees points left
	//circle
	move_to(x, y);
	set_pen_color(color::black);
	set_pen_width(280);
	draw_distance(1);
	set_pen_color(color::white);
	set_pen_width(270);
	draw_distance(1);
	note_position();
	//outer lines (12)
	//Center
	move_to(x, y);
	set_pen_color(color::black);
	set_pen_width(5);
	draw_distance(1);
	note_position();
	//12 [good]
	move_to(x, y - 110);
	set_pen_color(color::black);
	set_heading_degrees(0);
	set_pen_width(2);
	draw_distance(20);
	note_position();
	//1
	move_to(x + 55, y - 95);
	set_pen_color(color::black);
	set_heading_degrees(30);
	set_pen_width(2);
	draw_distance(20);
	note_position();
	//2
	move_to(x + 95, y - 55);
	set_pen_color(color::black);
	set_heading_degrees(60);
	set_pen_width(2);
	draw_distance(20);
	note_position();

	//3 [good]
	move_to(x + 110, y);
	set_pen_color(color::black);
	set_heading_degrees(90);
	set_pen_width(2);
	draw_distance(20);
	note_position();

	//4
	move_to(x + 95, y + 55);
	set_pen_color(color::black);
	set_heading_degrees(120);
	set_pen_width(2);
	draw_distance(20);
	note_position();
	//5
	move_to(x + 55, y + 95);
	set_pen_color(color::black);
	set_heading_degrees(150);
	set_pen_width(2);
	draw_distance(20);
	note_position();
	//6 [good]
	move_to(x, y + 110);
	set_pen_color(color::black);
	set_heading_degrees(180);
	set_pen_width(2);
	draw_distance(20);
	note_position();
	//7
	move_to(x - 55, y + 95);
	set_pen_color(color::black);
	set_heading_degrees(210);
	set_pen_width(2);
	draw_distance(20);
	note_position();
	//8
	move_to(x - 95, y + 55);
	set_pen_color(color::black);
	set_heading_degrees(240);
	set_pen_width(2);
	draw_distance(20);
	note_position();
	//9 [good]
	move_to(x - 110, y);
	set_pen_color(color::black);
	set_heading_degrees(270);
	set_pen_width(2);
	draw_distance(20);
	note_position();
	// 10
	move_to(x - 95, y - 55);
	set_pen_color(color::black);
	set_heading_degrees(300);
	set_pen_width(2);
	draw_distance(20);
	note_position();
	// 11
	move_to(x - 55, y - 95);
	set_pen_color(color::black);
	set_heading_degrees(330);
	set_pen_width(2);
	draw_distance(20);
	note_position();
}

void small_hand(int x, int y, int time) //hours
{
	move_to(x, y);
	set_pen_color(color::red);
	set_heading_degrees(30 * hour(time));
	set_pen_width(6);
	draw_distance(75);
}

void big_hand(int x, int y, int time) //minutes
{
	move_to(x, y);
	set_pen_color(color::black);
	set_heading_degrees(6 * minute(time));
	set_pen_width(5);
	draw_distance(95);
}

void second_hand(int x, int y, int time) //seconds
{
	move_to(x, y);
	set_pen_color(color::blue);
	set_heading_degrees(6 * second(time));
	set_pen_width(3);
	draw_distance(110);
}

void display_hour(int x, int y, int time)
{
	move_to(x - 380, y - 550);
	set_pen_color(color::black);
	set_font_size(50);
	write_int(hour(time));
	write_string(":");
}

void display_minute(int x, int y, int time)
{
	move_to(x - 380, y - 550);
	set_pen_color(color::black);
	set_font_size(50);
	if (minute(time) < 10)
		write_string("0");
	write_int(minute(time));
}

void display_day_night(int x, int y, int time)
{
	move_to(x - 380, y - 550);
	set_pen_color(color::black);
	set_font_size(50);
	write_string(day_night(time));
}

void progress_bar(int x, int y, int time)
{
	move_to(x - 550, y - 150);
	set_pen_color(color::grey);
	set_pen_width(30);
	set_heading_degrees(90);
	draw_distance(504);

	move_to(x - 550, y - 150);
	set_pen_color(color::light_green);
	set_pen_width(30);
	set_heading_degrees(90);
	draw_distance(21 * time / 10000);
}

void weeks(int x, int y, int date)
{
	move_to(x - 370, y - 100);
	set_pen_color(color::black);
	set_font_size(50);
	write_string("Sunday");
}

void date_number(int x, int y, int date)
{
	move_to(x - 560, y - 50);
	set_pen_color(color::black);
	set_font_size(50);
	write_int(day(date));

	int m = day(date);
	int d = day(date) % 10;
	if (d == 1)
		write_string("st");
	else if (d == 2)
		write_string("nd");
	else if (d == 3)
		write_string("rd");
	else
		write_string("th");
}

void month_name(int x, int y, int date)
{
	move_to(x - 400, y - 50);
	set_pen_color(color::black);
	set_font_size(50);

	int m = month(date);
	if (m == 1)
		write_string("January");
	else if (m == 2)
		write_string("February");
	else if (m == 3)
		write_string("March");
	else if (m == 4)
		write_string("April");
	else if (m == 5)
		write_string("May");
	else if (m == 6)
		write_string("June");
	else if (m == 7)
		write_string("July");
	else if (m == 8)
		write_string("August");
	else if (m == 9)
		write_string("September");
	else if (m == 10)
		write_string("October");
	else if (m == 11)
		write_string("November");
	else if (m == 12)
		write_string("December");
}

void year_number(int x, int y, int date)
{
	move_to(x - 130, y - 50);
	set_pen_color(color::black);
	set_font_size(50);
	write_int(year(date));
}

void main()
{
	int  time = get_clock_time();
	int  date = get_calendar_date();
	make_window(600, 600);
	print("second: ");  print(second(time)); new_line();

	while (true) //allows time to continue
	{
		time = get_clock_time();
		date = get_calendar_date();
		print("year: ");  print(year(date));   new_line();
		print("month: ");  print(month(date));  new_line();
		print("day: ");  print(day(date));    new_line();
		print("hour: ");  print(hour(time)); print(day_night(time));   new_line();
		print("minute: ");  print(minute(time)); new_line();
		clock_dial(300, 250);
		big_hand(300, 250, time);
		small_hand(300, 250, time);
		second_hand(300, 250, time);
		display_hour(600, 600, time);
		display_minute(630, 600, time);
		display_day_night(670, 600, time);
		progress_bar(600, 600, time);
		weeks(600, 600, date);
		date_number(600, 600, date);
		month_name(600, 600, date);
		year_number(600, 600, date);
		wait(0.5);
		clear();
	}
}
