#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

//Deklaracje funkcji:

bool 	sprawdz_nazwe(string);
bool 	sprawdz_rok(int);
bool 	sprawdz_miesiac(int);
bool 	sprawdz_dzien(int);
string 	pomiedzy(string input, string before, string after);
int 	string_na_int(string input);
int 	pobierz_numer(string input);
void 	pobierz_date(string date, int &RRRR , int &MM, int &DD);

int main()
{
	int RRRR, MM, DD;
	string imie, nazwisko;
	string input;
	string data;

	while (getline(cin, input))
	{
		imie = pomiedzy(input, "Imie: ", ";");
		nazwisko = pomiedzy(input, "Nazwisko: ", ";");
		data = input.substr(input.find("Data ur.: ") + string("Data ur.: ").length(), string::npos);
		pobierz_date(data, RRRR, MM, DD);

		if (!sprawdz_nazwe(imie))
			cout << 0 << endl;
		else if (!sprawdz_nazwe(nazwisko))
			cout << 1 << endl;
		else if (!(sprawdz_rok(RRRR) && sprawdz_miesiac(MM) && sprawdz_dzien(DD)))
			cout << 2 << endl;
		else
			cout << 3 << endl;
	}

	return 0;
}

// Ciala funkcji:

bool sprawdz_nazwe(string name)
{
	if (!isupper(name[0]))
		return false;
	for (int i = 1; i < name.length(); ++i)
		if (!islower(name[i]))
			return false;

	return true;
}

bool sprawdz_rok(int RRRR)
{
	return (RRRR >= 1900 && RRRR <= 2000);
}

bool sprawdz_miesiac(int MM)
{
	return (MM >= 1 && MM <= 12);
}

bool sprawdz_dzien(int DD)
{
	return (DD >= 1 && DD <= 31);
}

string pomiedzy(string input, string before, string after)
{
	size_t start = input.find(before) + before.length();
	size_t end = input.find(after, start);

	return input.substr(start, end - start);
}

int string_na_int(string input)
{
	int ret;

	stringstream ss;
	ss << input;
	ss >> ret;

	return ret;
}

int pobierz_numer(string input)
{
	string number;
	int i = 0;

	while (input[i] >= '0' && input[i] <= '9')
	{
		number += input[i];
		++i;
	}

	return string_na_int(number);
}

void pobierz_date(string date, int &RRRR , int &MM, int &DD)
{
	int i = 0;

	RRRR = pobierz_numer(date);
	while (date[i] >= '0' && date[i] <= '9')
		++i;
	++i;
	MM = pobierz_numer(date.substr(i, string::npos));
	while (date[i] >= '0' && date[i] <= '9')
		++i;
	++i;
	DD = pobierz_numer(date.substr(i, string::npos));
}
