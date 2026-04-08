#include <iostream>
using namespace std;

void count(int A, bool foward)
{
	if (A > 0)
	{
		if (foward)
		{
			cout << " " << A;
			count(A - 1, foward);
		}
		else
		{
			count(A - 1, foward);
			cout << " " << A;
		}
	}
}

void main()
{
	count(1, true);
	cout << '\n';
	count(2, false);
	count(1, true);
	cout << '\n';
	count(3, false);
	count(2, true);
	cout << '\n';
	count (2, false);
	count(1, true);
	cout << '\n';
	count(1, true);
}
