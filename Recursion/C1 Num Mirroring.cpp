#include <iostream>
using namespace std;

void print_foward(int const A)
{
	if (A > 0)
	{
		print_foward(A - 1);
		cout << A;
	}
}

void print_backwards(int const A)
{
	if (A > 0)
	{
		cout << A;
		print_backwards(A - 1);
	}
}

void main()
{
	print_foward(5);
	print_backwards(6);
}
