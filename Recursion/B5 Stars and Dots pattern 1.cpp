#include "iostream"

using namespace std;

int spaces(int B)
{
	if (B > 1)
	{
		cout << " .";
		spaces(B - 1); /*Bascially ends printing spaces so that it doesn't just keep move at the same time as it increases. Ex) space(2) will print a space but it will 
		then call space (1) whcih prints another space giving 2 spaces then it will call space(0) which ends so that it can created the downward slope*/
	}
	return 0;
}

int stars(int A)
{
	if (A > 0)
	{
		cout << "*";
		stars(A - 1); //this allows it to called the next number ex) when calling star (8) it will allow us to print 8 by calling the previous stars (8 - 1) creating that donward slope
	}
	return 0;
}

int uptriangle(int B, int A)
{
	if (A > 0)
	{
		spaces(B); //if i put cout it will call the 0s I return creating extra zeros
		stars(A);
		spaces(B);
		cout << '\n';
		uptriangle(B + 1, A - 2);
	}
	return 0;
}

int main()
{
	uptriangle(1, 9);
	return 0;
}
