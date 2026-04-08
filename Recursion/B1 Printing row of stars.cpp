#include "library.h"

void stars(int const A)
{
	if (A > 0)
		// A is less than or equal to B
	{
		print("*");
		stars(A - 1);
	}

}
void main()
{
	stars(7);
}
