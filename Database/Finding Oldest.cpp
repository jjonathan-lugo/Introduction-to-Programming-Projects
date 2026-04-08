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

persons find_oldest(persons y[], int size)
{
	persons oldest = y[0];
	for (int i = 0; i < size ; i++)
	{
		if (y[i].year < oldest.year)
		{
			oldest = y[i];
		}
		else if (y[i].year == oldest.year)
			{
				if (y[i].month < oldest.month)
				{
					oldest = y[i];
				}
			else if (y[i].month == oldest.month && y[i].day < oldest.day)
					{			 			
						oldest = y[i];
					}
			}	
	}
	return oldest;
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

	persons Old = find_oldest(y, 1000);
	cout << Old.social << " " << Old.day << " " << Old.month << " " << Old.year << " " << Old.first_name << " " << Old.last_name << " " << Old.balance << '\n';
	return 0;
}
