#include <iostream>
using namespace std;

void stars(int const x)
{
	if (x <= 6)
		// A is less than or equal to B
	{
		cout << x;
		stars(x + 1);
	}

}
void main()
{
	stars(0);
}
