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
	
	cout << "Type name" << '\n';
	string first_name; 
	string last_name;
	cin >> first_name >> last_name;
	persons name = search(first_name, last_name, y, 1000);
	cout << name.social << " " << name.day << " " << name.month << " " << name.year << " " << name.first_name << " " << name.last_name << " " << name.balance << '\n';

	return 0;
}
