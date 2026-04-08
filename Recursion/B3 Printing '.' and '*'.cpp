#include <iostream>
using namespace std;

void dots(int const A)
{
	if (A <= 0)
	{
		cout << ".";
		dots(A - 1);
	}
}

void stars(int const B)
{
	if (B > 0)
	{
		cout << "*";
		stars(B - 1);
	}
}

void dots_stars(int const A, int const B)
{
	dots(A);
	stars(B);
	dots(A);
}

void main()
{
	dots_stars(3, 4);
}
