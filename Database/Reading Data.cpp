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
	for (int i = 0; i < 10; i++)
	{
		cout << y[i].social << " " << y[i].day << " " << y[i].month << " " << y[i].year << " " << y[i].first_name << " " << y[i].last_name << " " << y[i].balance << '\n';
	}
}
