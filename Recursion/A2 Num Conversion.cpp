#include <iostream>
using namespace std;

void print_mph(const int x)
{
	cout << ((int)(x / 1.609344 + 0.5));
}

void print_five(int x, int y)
{
	if (x <= y)
	{
		cout << x << " kph is ";
		print_mph(x);
		cout << " mph" << '\n';
		print_five(x + 5, y);
	}
}

void main()
{
	print_five(10, 30);
}
