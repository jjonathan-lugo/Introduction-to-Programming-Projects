#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//people file /home/118/peoplefile1.txt

struct persons {
	int social, day, month, year;
	string first_name, last_name;
	double balance;
};

persons search(string first_name, string last_name, persons y[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (first_name == y[i].first_name && last_name == y[i].last_name)
		{
			return y[i];
		}
	}
	return persons {};
}

int find_youngest(persons y[], int size)
{
	persons youngest = y[0];
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (y[i].year > youngest.year)
		{
			youngest = y[i];
			index = i;
		}
		else if (y[i].year == youngest.year)
		{
			if (y[i].month > youngest.month)
			{
				youngest = y[i];
				index =  i;
			}
			else if (y[i].month == youngest.month && y[i].day > youngest.day)
			{
				youngest = y[i];
				index = i;
			}
		}
	}
	return index;
}

int main()
{
	ifstream ppl;
	ppl.open("peoplefile1.txt");
	if (ppl.fail())
	{
		cout << "can't open/n";
		exit(1);
	}

	persons y[1000] = {};
	int i = 0;
	while (true)
	{
		persons x;
		ppl >> x.social >> x.day >> x.month >> x.year >> x.first_name >> x.last_name >> x.balance; //x. : just specifies
		if (ppl.fail())
		{
			break;
		}
		y[i] = x; //allow any index value
		i++; //increase index each time
	}

	ppl.close();

	int oldest = find_youngest(y, 1000);
	cout << y[0].social << " " << y[0].day << " " << y[0].month << " " << y[0].year << " " << y[0].first_name << " " << y[0].last_name << " " << y[0].balance << '\n';
	persons temp = y[0]; //allow for switch
	y[0] = y[oldest];
	y[oldest] = temp;
	cout << y[0].social << " " << y[0].day << " " << y[0].month << " " << y[0].year << " " << y[0].first_name << " " << y[0].last_name << " " << y[0].balance << '\n';
	return 0;
}
