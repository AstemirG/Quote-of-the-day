#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
using namespace std;
random_device ran;
class quote
{
protected:
	vector<string> quote_arr = { " " };
	string filename = "Quote.txt";
	int count_quote = 0;
public:
	quote() {};
	void show_random_quote();
	void fillarr();
	string getfilename() { return filename; }
	friend ostream& operator<<(ostream& os, quote& test);
};
void quote::show_random_quote()
{
	cout << quote_arr[ran() % quote_arr.size()] << endl;
}
void quote::fillarr()
{
	ifstream of;
	of.open(filename);
	if (of.is_open())
	{
		while (!of.eof())
		{
			string buff;
			getline(of, buff);
			quote_arr.emplace_back(buff);
			++count_quote;
		}
	}
	else
		cout << "invalid file ";
}
ostream& operator<<(ostream& os, quote& test)
{
	for (int i = 0; i < test.quote_arr.size(); i++)
	{
		cout << test.quote_arr[i] << endl;
	}
	return os;
}
int main()
{
	setlocale(LC_ALL, "rus");
	quote test;
	short menu=1;
	test.fillarr();
	do
	{
		cout << "1)Показать цитату дня \n"
			"2)Показать все цитаты \n"
			"0)Закрыть программу \n";
		cin >> menu;
		if (menu == 1)
		{
			while (menu!=2)
			{
				test.show_random_quote();
				cout << "1)Показать другую цитату \n"
					"2)Назад \n";
				cin >> menu;
			}
		}
		else if (menu == 2)
		{
			cout << test;
		}
	} while (menu);
}