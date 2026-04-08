#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//people file /home/118/peoplefile1.txt
//tiemfunction /home/class/een118/timefunc.txt

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

int find_youngest(persons y[], int size, int start)
{
	persons youngest = y[start];
	int index = start; //bruh
	for (int i = start; i < size; i++)
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

void print(persons y[])
{
	for (int i = 0; i < 1000; i++)
	{
		cout << y[i].social << " " << y[i].day << " " << y[i].month << " " << y[i].year << " " << y[i].first_name << " " << y[i].last_name << " " << y[i].balance << '\n';
	}
}

void sort(persons y[], int size)
{
	persons temp;
	int index = 0;
	for (int i = 0; i < size; i++) 
	{
		index = find_youngest(y, size, i);
			temp = y[i];
			y[i] = y[index];
			y[index] = temp;
			//cout << y[i].social << " " << y[i].day << " " << y[i].month << " " << y[i].year << " " << y[i].first_name << " " << y[i].last_name << " " << y[i].balance << '\n';
	}
}

int main()
{
	ifstream ppl;
	ppl.open("/home/118/peoplefile1.txt");
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

	sort(y, 1000);
	print(y);
	return 0;
}
