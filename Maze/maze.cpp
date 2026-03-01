#include "library.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char maze_array[11][31];

// Store enemy positions as a fixed-size array (assuming a max of 100 enemies)
pair<int, int> enemies[5];
int num_enemies = 0;  // To track the number of enemies

int x_pos_start;
int y_pos_start;

int x_pos_end;
int y_pos_end;

bool auto_move = false;

void read_maze()
{
    ifstream maze;
    maze.open("maze.txt");
    if (maze.fail())
    {
        cout << "Error" << endl;
        exit(1);
    }
    char ch;
    int i = 0, j = 0;
    while (maze.get(ch))
    {
        if (ch != '\n')
        {
            if (ch == '#')
            {
                maze_array[i][j] = '@';
            }
            else if (ch == '~')
            {
                maze_array[i][j] = '_';
            }
            else if (ch == '+')
            {
                maze_array[i][j] = 'S';
                x_pos_start = j;
                y_pos_start = i;
            }
            else if (ch == '$')
            {
                maze_array[i][j] = 'E';
                x_pos_end = j;
                y_pos_end = i;
            }
            else if (ch == 'E')
            {
                maze_array[i][j] = 'B';
                if (num_enemies < 100)  // Don't exceed max enemies
                {
                    enemies[num_enemies++] = { i, j };  // Store the position of each enemy
                }
            }

            j++;

            if (j == 31)
            {
                j = 0;
                i++;
            }
        }
    }
    maze.close();
}

void print_maze()
{
    for (int i = 0; i < 11; ++i)
    {
        for (int j = 0; j < 31; ++j)
        {
            cout << maze_array[i][j];
        }
        cout << '\n';
    }
    cout << "Start Coor: " << x_pos_start << ", " << y_pos_start << '\n';
    cout << "End Coor: " << x_pos_end << ", " << y_pos_end << '\n';
}

void draw_square(int x, int y, string clr)
{
    set_heading_degrees(90);
    set_pen_width(1);
    set_pen_color(color::black);
    move_to(x, y);
    start_shape();
    draw_distance(26);
    note_position();
    turn_right_by_degrees(90);
    draw_distance(26);
    note_position();
    turn_right_by_degrees(90);
    draw_distance(26);
    note_position();
    turn_right_by_degrees(90);
    draw_distance(26);
    note_position();

    if (clr == "grey")
    {
        fill_shape(color::grey);
    }
    else if (clr == "red")
    {
        fill_shape(color::red);
    }
    else if (clr == "green")
    {
        fill_shape(color::green);
    }
    else if (clr == "blue")
    {
        fill_shape(color::blue);
    }
    else
    {
        fill_shape(color::white);
    }
    move_to(x, y);
}

void draw_maze()
{
    for (int i = 0; i < 11; ++i)
    {
        for (int j = 0; j < 31; ++j)
        {
            if (maze_array[i][j] == '@')
            {
                draw_square(j * 26, i * 26, "grey");
            }
            else if (maze_array[i][j] == '_')
            {
                draw_square(j * 26, i * 26, "white");
            }
            else if (maze_array[i][j] == 'S')
            {
                draw_square(j * 26, i * 26, "green");
            }
            else if (maze_array[i][j] == 'B')
            {
                draw_square(j * 26, i * 26, "blue");
            }
            else
            {
                draw_square(j * 26, i * 26, "red");
            }
        }
    }
}

// Checks for collision between the robot and any enemy
bool check_collision()
{
    for (int i = 0; i < num_enemies; ++i)
    {
        if (x_pos_start == enemies[i].second && y_pos_start == enemies[i].first)
        {
            return true;  // Collision detected
        }
    }
    return false;
}

void auto_robot()
{
    int direction = rand() % 4; // Random direction

    bool moved = false;

    while (!moved)
    {
        if (direction == 0 && y_pos_start > 0 && maze_array[y_pos_start - 1][x_pos_start] != '@')
        {
            maze_array[y_pos_start - 1][x_pos_start] = 'S';
            maze_array[y_pos_start][x_pos_start] = '_';
            y_pos_start--;
            moved = true;
        }
        else if (direction == 1 && x_pos_start < 30 && maze_array[y_pos_start][x_pos_start + 1] != '@')
        {
            maze_array[y_pos_start][x_pos_start + 1] = 'S';
            maze_array[y_pos_start][x_pos_start] = '_';
            x_pos_start++;
            moved = true;
        }
        else if (direction == 2 && y_pos_start < 10 && maze_array[y_pos_start + 1][x_pos_start] != '@')
        {
            maze_array[y_pos_start + 1][x_pos_start] = 'S';
            maze_array[y_pos_start][x_pos_start] = '_';
            y_pos_start++;
            moved = true;
        }
        else if (direction == 3 && x_pos_start > 0 && maze_array[y_pos_start][x_pos_start - 1] != '@')
        {
            maze_array[y_pos_start][x_pos_start - 1] = 'S';
            maze_array[y_pos_start][x_pos_start] = '_';
            x_pos_start--;
            moved = true;
        }

        direction = rand() % 4; // Randomize the next direction
    }
}

void auto_enemy()
{
    int direction;

    for (int i = 0; i < num_enemies; ++i)
    {
        int y_pos_enemy = enemies[i].first;
        int x_pos_enemy = enemies[i].second;

        direction = rand() % 4;

        bool moved = false;

        while (!moved)
        {
            if (direction == 0 && y_pos_enemy > 0 && maze_array[y_pos_enemy - 1][x_pos_enemy] != '@' && !(x_pos_enemy == x_pos_end && y_pos_enemy - 1 == y_pos_end))
            {
                maze_array[y_pos_enemy - 1][x_pos_enemy] = 'B';
                maze_array[y_pos_enemy][x_pos_enemy] = '_';
                y_pos_enemy--;
                moved = true;
            }
            else if (direction == 1 && x_pos_enemy < 30 && maze_array[y_pos_enemy][x_pos_enemy + 1] != '@' && !(x_pos_enemy + 1 == x_pos_end && y_pos_enemy == y_pos_end))
            {
                maze_array[y_pos_enemy][x_pos_enemy + 1] = 'B';
                maze_array[y_pos_enemy][x_pos_enemy] = '_';
                x_pos_enemy++;
                moved = true;
            }
            else if (direction == 2 && y_pos_enemy < 10 && maze_array[y_pos_enemy + 1][x_pos_enemy] != '@' && !(x_pos_enemy == x_pos_end && y_pos_enemy + 1 == y_pos_end))
            {
                maze_array[y_pos_enemy + 1][x_pos_enemy] = 'B';
                maze_array[y_pos_enemy][x_pos_enemy] = '_';
                y_pos_enemy++;
                moved = true;
            }
            else if (direction == 3 && x_pos_enemy > 0 && maze_array[y_pos_enemy][x_pos_enemy - 1] != '@' && !(x_pos_enemy - 1 == x_pos_end && y_pos_enemy == y_pos_end))
            {
                maze_array[y_pos_enemy][x_pos_enemy - 1] = 'B';
                maze_array[y_pos_enemy][x_pos_enemy] = '_';
                x_pos_enemy--;
                moved = true;
            }

            direction = rand() % 4;
        }
        enemies[i] = { y_pos_enemy, x_pos_enemy };
    }
}

void robot_movement()
{
    char temp;
    while (true)
    {
        if (check_collision())
        {
            cout << "Hit Enemies.\n";
            break;
        }

        char c = wait_for_key_typed();

        if (c == 'M' || c == 'm')
        {
            auto_move = !auto_move;
            if (auto_move)
            {
                cout << "Switched to Auto Mode\n";
            }
            else
            {
                cout << "Switched to Manual Mode\n";
            }

        }

        if (auto_move)
        {
            auto_robot();
            auto_enemy();
            draw_maze();

            // Check if the robot has reached to the end
            if (x_pos_start == x_pos_end && y_pos_start == y_pos_end)
            {
                cout << "Treasure found!\n";
                break;
            }
        }
        else if (c == 'w')
        {
            if (y_pos_start > 0 && maze_array[y_pos_start - 1][x_pos_start] != '@')
            {
                maze_array[y_pos_start - 1][x_pos_start] = 'S';
                maze_array[y_pos_start][x_pos_start] = '_';
                y_pos_start = y_pos_start - 1;
            }
        }
        else if (c == 'd')
        {
            if (x_pos_start < 30 && maze_array[y_pos_start][x_pos_start + 1] != '@')
            {
                maze_array[y_pos_start][x_pos_start + 1] = 'S';
                maze_array[y_pos_start][x_pos_start] = '_';
                x_pos_start = x_pos_start + 1;
            }
        }
        else if (c == 's')
        {
            if (y_pos_start < 10 && maze_array[y_pos_start + 1][x_pos_start] != '@')
            {
                maze_array[y_pos_start + 1][x_pos_start] = 'S';
                maze_array[y_pos_start][x_pos_start] = '_';
                y_pos_start = y_pos_start + 1;
            }
        }
        else if (c == 'a')
        {
            if (x_pos_start > 0 && maze_array[y_pos_start][x_pos_start - 1] != '@')
            {
                maze_array[y_pos_start][x_pos_start - 1] = 'S';
                maze_array[y_pos_start][x_pos_start] = '_';
                x_pos_start = x_pos_start - 1;
            }
        }
        if (x_pos_start == x_pos_end && y_pos_start == y_pos_end)
        {
            cout << "Treasure found!\n";
            break;
        }
        auto_enemy();
        draw_maze();
    }
}

void main()
{
	read_maze();
	print_maze();

	make_window(806, 286);
	draw_maze();
	robot_movement();
}
