#include <iostream>
using namespace std;


int month_length(int year, int month)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;

    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;

    if (year % 4 == 0) //mulitple of 4 will print 29 b/c every 4 year Feb is 29
        return 29;
    else
        return 28;
}


int sum_month(int const year, int const month) //this function goes back to the first month if call month 6 it will go back to 1 and add up
{
    if (month > 1)
    {
        return month_length(year, month - 1) + sum_month(year, month - 1);
    }
    return 0;
}

int day_year(int year, int month, int day)
{
    return sum_month(year, month) + day;
    //add the day in month you call for if day = 12 it will add 12 plus the previous months dates
}

int sum_year(int year) //core function that makes everything work
{
    if (year >= 0)
    {
        if (year % 4 == 0 && !(year % 100 == 0)) // if divisable by 4 but not 100 it will be a leap year
            return(366);
        else if (year % 400 == 0) // consider 100 years
            return(366);
        else return(365);
    }
    return 0;
}

int total_day_years(int year) //goes back to previous years ex if year = 400 it will go back to year one
{
    if (year > 0)
    {
        return sum_year(year - 1) + total_day_years(year - 1);
    }
    return 0;
}

int const day_century(int year, int month, int day) //add all the previous years to year inputted
{
    return total_day_years(year) + day_year(year, month, day);
}

int day_week(int year, int month, int day)
{
    return (day_century(year, month, day) + 5) % 7; //adding 5 ensures weekday start from Sun (day 0). % 7 ensures the days repeatevery 7 days which aligns the days of the week
}

int print_calendar(int year, int month)
{
    int num_days = month_length(year, month);
    int start_day = day_week(year, month, 1);

    const char* month_names[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    cout << "     " << month_names[month - 1] << " " << year << '\n'; // month - 1 gives the right month
    cout << " Su Mo Tu We Th Fr Sa " << '\n'; // Calendar header

    // Print spaces for the first week if the month doesn't start on Sunday
    for (int i = 0; i < start_day; i++) {
        cout << "   "; // 3 spaces to align days
    }

    // Print all days of the month
    for (int day = 1; day <= num_days; day++) {
        if (day < 10) {
            cout << "  " << day; // Adds space for single-digits
        }
        else {
            cout << " " << day;  // Normal spacing for double-digits
        }

        if ((day + start_day) % 7 == 0 || day == num_days) {
            cout << '\n'; // New line after Saturday or last day of the month
        }
    }
    return 0;
}

int main() {
    int year, month;

    cout << "Enter year: ";
    cin >> year;

    cout << "Enter month: ";
    cin >> month;

    if (month >= 1 && month <= 12) {
        print_calendar(year, month);
    }
    else {
        cout << "Error" << '\n';
    }

    return 0;
}
