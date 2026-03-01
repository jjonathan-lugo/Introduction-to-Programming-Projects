#include "library.h"
#include <iostream>

using namespace std;

void draw_rectangle(int x, int y, int width, int height)
{
    start_shape();
    move_to(x, y);
    note_position();
    set_heading_degrees(90);
    draw_distance(width);
    note_position();
    turn_right_by_degrees(90);
    draw_distance(height);
    note_position();
    turn_right_by_degrees(90);
    draw_distance(width);
    note_position();
    turn_right_by_degrees(90);
    draw_distance(height);
    note_position();
    fill_shape();
}

void value_in_rectangle(int x, int y, int width, int height, int num)
{
    set_pen_color(color::black);
    draw_rectangle(x, y, width, height);
    move_to(70, 120);
    set_font_size(150);
    set_pen_color(color::green);
    write_string(num);
}

void draw_circle(double const x, double const y, double const radius)
{
    double const pi = acos(-1.0);
    double const circumference = 2 * radius * pi;
    double const side = circumference / 360;

    // Move to the starting position and set the pen
    move_to(x, y - radius);
    set_heading_degrees(90);
    set_pen_width(5);
    set_pen_color(color::black);

    // Start drawing the circle
    start_shape();
    for (int i = 0; i < 360; ++i)
    {
        draw_distance(side);  // Draw a tiny segment of the circle
        turn_right_by_degrees(1);// Turn 1 degree after each segment
        note_position();
    }
    fill_shape(color::grey);

}

void rows_button(double const x, double const y, double const radius)
{
    for (int i = y; i < 670; i += 150) //y-axis. Make Column
    {
        for (int j = x; j <= 700; j += 150) //x-axis. Make rows
        {
            draw_circle(j, i, radius);
        }
    }

}

void rows_columns_character(double const x, double const y)
{
    set_font_size(80);

    for (int i = y; i < 150 * 5 + y; i += 150) //y-axis. Make Column
    {
        for (int j = x; j <= 150 * 5 + x; j += 150) //x-axis. Make rows
        {
            move_to(j, i);
            int sum = j + i;
            if (i == y && j == x)
                write_string("7");
            else if (i == y && j == x + 150)
                write_string("8");
            else if (i == y && j == x + 150 * 2)
                write_string("9");
            else if (i == y && j == x + 150 * 3)
                write_string("+");
            else if (i == y && j == x + 150 * 4)
                write_char(L'ˆ');

            if (i == y + 150 && j == x)
                write_string("4");
            else if (i == y + 150 && j == x + 150)
                write_string("5");
            else if (i == y + 150 && j == x + 150 * 2)
                write_string("6");
            else if (i == y + 150 && j == x + 150 * 3)
                write_string("-");
            else if (i == y + 150 && j == x + 150 * 4)
                write_char(L'©');

            if (i == y + 300 && j == x)
                write_string("1");
            else if (i == y + 300 && j == x + 150)
                write_string("2");
            else if (i == y + 300 && j == x + 150 * 2)
                write_string("3");
            else if (i == y + 300 && j == x + 150 * 3)
                write_char(L'×');
            else if (i == y + 300 && j == x + 150 * 4)
                write_char(L'∑');

            if (i == y + 450 && j == x)
                write_string("C");
            else if (i == y + 450 && j == x + 150)
                write_string("0");
            else if (i == y + 450 && j == x + 150 * 2)
                write_string("=");
            else if (i == y + 450 && j == x + 150 * 3)
                write_char(L'÷');
            else if (i == y + 450 && j == x + 150 * 4)
                write_string("M");
        }
    }
}


int clicking()
{
    wait_for_mouse_click();
    int x = get_click_x(), y = get_click_y();

    if (x > 50 && x < 150 && y > 165 && y < 265)
        return 7;
    else if (x > 200 && x <= 300 && y > 165 && y < 265)
        return 8;
    else if (x > 350 && x < 450 && y > 165 && y < 265)
        return 9;
    else if (x > 500 && x < 600 && y > 165 && y < 265)
        return 10;
    else if (x > 650 && x < 750 && y > 165 && y < 265)
        return 11;

    if (x > 50 && x < 150 && y > 315 && y < 415)
        return 4;
    else if (x > 200 && x < 300 && y > 315 && y < 415)
        return 5;
    else if (x > 350 && x < 450 && y > 315 && y < 415)
        return 6;
    else if (x > 500 && x < 600 && y > 315 && y < 415)
        return 12;
    else if (x > 650 && x < 750 && y > 315 && y < 415)
        return 13;

    if (x > 50 && x < 150 && y > 465 && y < 565)
        return 1;
    else if (x > 200 && x < 300 && y > 465 && y < 565)
        return 2;
    else if (x > 350 && x < 450 && y > 465 && y < 565)
        return 3;
    else if (x > 500 && x < 600 && y > 465 && y < 565)
        return 14;
    else if (x > 650 && x < 750 && y > 465 && y < 565)
        return 15; //rename with num 

    if (x > 50 && x < 150 && y > 615 && y < 715)
        return 16;
    else if (x > 200 && x < 300 && y > 615 && y < 715)
        return 0;
    else if (x > 350 && x < 450 && y > 615 && y < 715)
        return 17;
    else if (x > 500 && x < 600 && y > 615 && y < 715)
        return 18;
    else if (x > 650 && x < 750 && y > 615 && y < 715)
        return 19;
}

int addition(int x) //create new function and call in function
{
    int y = 0;
    int temp = 0;

    while (true)
    {
        value_in_rectangle(50, 10, 700, 140, y);
        temp = clicking();
        if (temp <= 9)
        {
            y = (y * 10) + temp;
            continue;
        }
        if (temp == 16)
        {
            y = 0;
            continue;
        }
        return x + y;
    }
}

int exponent(int x) // x^2
{
        int y = 0;
        int temp = 0;

        while (true) 
        {
            value_in_rectangle(50, 10, 700, 140, y);
            temp = clicking();
            if (temp <= 9)
            {
                y = (y*10) + temp;
                continue;
            }
            if (temp == 16)
            {
                y = 0;
                continue;
            }
            return pow(x,y);
        }
}

int subtraction(int x)
{
    int y = 0;
    int temp = 0;

    while (true) 
    {
        value_in_rectangle(50, 10, 700, 140, y);
        temp = clicking();
        if (temp <= 9)
        {
            y = (y * 10) + temp;
            continue;
        }
        if (temp == 16)
        {
            y = 0;
            continue;
        }
        return x - y;
    }
}

int Multiplication(int x)
{
    int y = 0;
    int temp = 0;

    while (true) 
    {
        value_in_rectangle(50, 10, 700, 140, y);
        temp = clicking();
        if (temp <= 9)
        {
            y = y = (y * 10) + temp;
            continue;
        }
        if (temp == 16)
        {
            y = 0;
            continue;
        }
        return y * x;
    }
}

int clear_num(int x)
{
    int y = 0;
    int temp = 0;

    while (true) 
    {
        value_in_rectangle(50, 10, 700, 140, y);
        temp = clicking();
        if (temp <= 9)
        {
            y = (y * 10) + temp;
            continue;
        }
        if (temp == 16)
        {
            y = 0;
            continue;
        }
        return x;
    }
}

int Division(int x)
{
    int y = 0;
    int temp = 0;

    while (true) 
    {
        value_in_rectangle(50, 10, 700, 140, y);
        temp = clicking();
        if (temp <= 9)
        {
            y = (y * 10) + temp;
            continue;
        }
        if (temp == 16)
        {
            y = 0;
            continue;
        }
        return x / y;
    }
}


int store(int x, int y)
{
    return x * 10 + y;   
    //if y =1 counter = 0 x = 0.. x = (0*10) + 1 = 1. if y = 2 counter = 1 x = 1 x = (1*10) + 2 = 12
    //[124] if y = 4 counter = 2 x = 12 x = (12*) + 12 = 124
    //[1245] if y = 5 counter = 3 x = 124 x = (124 * 10) + y = 1245

}

void main()
{
    int var = 0;
    make_window(800, 800);
    draw_rectangle(50, 10, 700, 140);
    rows_button(100, 215, 50);
    rows_columns_character(83, 235);
    cout << clicking();

    int x = 0; //store number whole value
    int temp = 0; //temperary . store what number clicked 

    while (true) //lopp
    {
        value_in_rectangle(50, 10, 700, 140, x);
        temp = clicking(); // if click 1 it gest stores
        if (temp <= 9) //special char not touched if less than 9 num touched
        {
            x = store(x, temp);
            continue;
        }

        cout << "here2" << temp;

        if (temp == 16) //if click C put 0
        {
            x= 0;
            continue;
        }

        if (temp == 10)
        {
            cout << "here";
            x = addition(x);
            cout << x;
            //return x;
        }

        if (temp == 11)
        {
            x = exponent(x);
            //return x;
        }

        if (temp == 12)
        {
            x = subtraction(x);
            //return x;
        }

        if (temp == 13) //clear the memory by setting it to zero (it’s a C inside a zero) [©] . clear sigma
        {
            var = 0;
            //return x;
        }

        if (temp == 14)
        {
            x = Multiplication(x);
            //return x;
        }

        if (temp == 15) //add whatever is on the display to the memory value [∑] . store value 
        {
            var = x;
            //return x;
        }

        if (temp == 16)
        {
            x = clear_num(x);
            //return x;
        }

        if (temp == 18)
        {
            x = Division(x);
            //return x;
        }

        if (temp == 19)
        {
           //recall the memory value so that it appears on the display and can be used in the next calculation. [M] recall sigma
            x = var;
            //return x;
        }
    }
}
