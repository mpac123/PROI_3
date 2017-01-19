#include "interfejs.h"
#include <cstring>
#include <fstream>
void Interfejs::Start()
{
	std::string s;
	std::cout << "Podaj nazwe menu: ";
	std::getline(std::cin,s);
	Obsluga M(s);
	Program(M);
}
void Interfejs::Program(Obsluga& M)
{
	std::ofstream file;
	file.open("output.txt");
	std::string s;
	do
	{
		std::cout << M;
		
		Wybor* wsk_wyb=M.wsk_kursor();
		Podmenu* wsk_menu;
		if((wsk_menu=dynamic_cast<Podmenu*>(wsk_wyb))==NULL)
		{
			std::cout << "[S] dol [W] gora [D] przypisz funkcje\n[D] wykonaj [X] usun [exit] wyjdz\n";
			std::cin >> s;
			ZarzadzajWyboremJedn(s,M);
		}
		else
		{
			std::cout << "[S] dol [W] gora [D] rozwin [A] zwin \n[M] dodaj menu [F] dodaj wybor jednoznaczny [X] usun [exit] wyjdz\n";
			std::cin >> s;
			ZarzadzajPodmenu(s,M);
		}
	}while(s!="exit");
	file << M;
	file.close();
}

void Interfejs::ZarzadzajPodmenu(std::string s, Obsluga& M)
{
	if (s=="S" or s=="s")
		M.Dalej();
	if (s=="W" or s=="w")
		M.Wstecz();
	if (s=="D" or s=="d")
		M.Rozwin();
	if (s=="A" or s=="a")
		M.Zwin();
	if (s=="M" or s=="m")
	{
		std::string nazwa;
		std::cout << "Podaj nazwe podmenu: ";
		std::cin.ignore();
		std::getline(std::cin,nazwa);
		M.DodajMenu(nazwa);
	}
	if (s=="F" or s=="f")
	{
		std::string nazwa;
		std::cout << "Podaj nazwe wyboru jednoznacznego: ";
		std::cin.ignore();
		std::getline(std::cin,nazwa);
		M.DodajWyborJedn(nazwa);
	}
	if (s=="X" or s=="x")
	{
		M.Usun();
	}
}

void Interfejs::ZarzadzajWyboremJedn(std::string s, Obsluga &M)
{
	if (s=="S" or s=="s")
		M.Dalej();
	if (s=="W" or s=="w")
		M.Wstecz();
	if (s=="r" or s=="R")
		M.Wykonaj();
	if (s=="d" or s=="D")
	{
		int n;
		std::cout << "Ktora funkcje przypisac? [1-5] ";
		std::cin >> n;
		M.PrzypiszFunkcje(n);
	}
	if (s=="X" or s=="x")
	{
		M.Usun();
	}
}
