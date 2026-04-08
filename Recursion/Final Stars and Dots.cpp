#include <iostream>
using namespace std;

int spaces(int B)
{
	if (B > 1)
	{
		cout << ".";
		spaces(B - 1);
	}
	return 0;
}

int stars(int A)
{
	if (A > 0)
	{
		cout << "*";
		stars(A - 1);
	}
	return 0;
}

int triangle(int B, int A)
{
	if (A <= 9)
	{
		spaces(B); 
		stars(A);
		spaces(B);
		cout << '\n';
		triangle(B - 1, A + 2);
	}
	return 0;
}

int uptriangle(int B, int A)
{
	if (A > 0)
	{
		spaces(B);
		stars(A);
		spaces(B);
		cout << '\n';
		uptriangle(B + 1, A - 2);
	}
	return 0;
}

int diamond()
{
	triangle(5, 1);
	uptriangle(1, 9);
	return 0;
}

int main()
{
	diamond();
	return 0;
}
