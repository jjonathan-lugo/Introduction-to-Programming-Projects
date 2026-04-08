#include <iostream>
using namespace std;

void sequence(int const A, int const B)
{
	if (A > 0, B <= 5)
	{
		cout << A << " " << B << '\n';
		sequence(A - 2, B + 1);
	}

}

void main()
{
	sequence(9, 1);
}
