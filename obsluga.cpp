#include "obsluga.h"

Obsluga::Obsluga(std::string s) : Menu(s) 
{
		Kursor=Menu.ZbiorWyborow.begin();
		Kursor++;
};

void Obsluga::DodajMenu(std::string s)
{
	Menu.DodajMenu(s,Kursor);
	//Dalej();
}

void Obsluga::DodajWyborJedn(std::string s)
{
	Menu.DodajWyborJedn(s,Kursor);
	//Dalej();
}

void Obsluga::Dalej()
{
	Kursor++;
}

void Obsluga::Wstecz()
{
	Kursor--;
}

void Obsluga::Wypisz()
{
	for (kursor it=Menu.ZbiorWyborow.begin(); it!=Menu.ZbiorWyborow.end(); it++)
	{
		std::cout << **it;
		if (Kursor==it)
			std::cout << " ***";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
