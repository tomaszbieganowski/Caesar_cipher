//	CEZAR_main.cpp 
//
//	
//	Program do szyfrowania i deszyfrowania tektu szyfrem przesuwającym
//	

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main()
{
	int opcja = 0;
    cout << "Wybierz odpowiednia opcje:\n 1.Szyfrowanie \n 2.Deszyfrowanie \n";
	cin >> opcja;

	int klucz = 0;
	cout << "Podaj wartosc klucza \n";
	cin >> klucz;

	string nazwa_pliku = "";
	cout << "podaj nazwe pliku \n";
	cin >> nazwa_pliku;
	nazwa_pliku += ".txt";

	fstream plikin;
	fstream plikout;

	plikin.open(nazwa_pliku.c_str(), std::ios::in);
		if (plikin.good() != true)
		{
			cout << "plik nie zostal wczytany \n";
		}

	plikout.open("out.txt", std::ios::out);

	char znak;

	if (opcja == 1)
	{
		while (plikin.get(znak))
		{
			if (isupper(znak))
			{
				if (int(znak + klucz) > 90)
				{
					plikout << char(znak + klucz - 26);
				}
				else
				{
					plikout << char(znak + klucz);
				}
			}
			if (islower(znak))
			{
				if (int(znak + klucz) > 122)
				{
					plikout << char(znak + klucz - 26);
				}
				else
				{
					plikout << char(znak + klucz);
				}
			}
			if (isdigit(znak))
			{
				if (int(znak + klucz) > 57)
				{
					plikout << char(znak + klucz - 10);
				}
				else
				{
					plikout << char(znak + klucz);
				}
			}
			if ((int)znak == 32 || (int)znak == 10)
			{
				plikout << znak;
			}
		}
		cout << "Plik zostal zaszyfrowany ! \n";
	}
	if (opcja == 2)
	{
		while (plikin.get(znak))
		{
			if (isupper(znak))
			{
				if (int(znak - klucz) < 65)
				{
					plikout << char(znak - klucz + 26);
				}
				else
				{
					plikout << char(znak - klucz);
				}
			}
			if (islower(znak))
			{
				if (int(znak - klucz) < 97)
				{
					plikout << char(znak - klucz + 26);
				}
				else
				{
					plikout << char(znak - klucz);
				}
			}
			if (isdigit(znak))
			{
				if (int(znak - klucz) < 48)
				{
					plikout << char(znak - klucz + 10);
				}
				else
				{
					plikout << char(znak - klucz);
				}
			}
			if ((int)znak == 32 || (int)znak == 10)
			{
				plikout << znak;
			}
		}
		cout << "Plik zostal rozszyfrowany ! \n";
	}

	plikin.close();
	plikout.close();

	return 0;
}