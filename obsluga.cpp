#include "obsluga.h"
void fun1()
{
	std::cout << "Jestem funkcja nr 1 ktora nic nie robi\n";
}
void fun2()
{
	std::cout << "Jestem funkcja nr 2 ktora nic nie robi\n";
}
void fun3()
{
	std::cout << "Jestem funkcja nr 3 ktora nic nie robi\n";
}
void fun4()
{
	std::cout << "Jestem funkcja nr 4 ktora nic nie robi\n";
}
void fun5()
{
	std::cout << "Jestem funkcja nr 5 ktora nic nie robi\n";
}
Obsluga::Obsluga(std::string s) : Menu(s) 
{
		Kursor=Menu.ZbiorWyborow.begin();
};

void Obsluga::DodajMenu(std::string s)
{
	try{
		Menu.DodajMenu(s,Kursor);
	}
	catch(char const* t)
	{
		std::cerr << t << std::endl;
	}
		
}

void Obsluga::DodajWyborJedn(std::string s)
{
	try
	{
		Menu.DodajWyborJedn(s,Kursor);
	}
	catch(char const* t)
	{
		std::cerr << t << std::endl;
	}
}

void Obsluga::PrzypiszFunkcje(int n)
{
	try
	{
		Wybor* wsk_wyb=(*Kursor);
		Jednoznaczny* wsk_jedn;
		if((wsk_jedn=dynamic_cast<Jednoznaczny*>(wsk_wyb))!=NULL)
		{
		if (n==1) wsk_jedn->PrzypiszFunkcje((&fun1));
		if (n==2) wsk_jedn->PrzypiszFunkcje((&fun2));
		if (n==3) wsk_jedn->PrzypiszFunkcje((&fun3));
		if (n==4) wsk_jedn->PrzypiszFunkcje((&fun4));
		if (n==5) wsk_jedn->PrzypiszFunkcje((&fun5));
		}
		else
			throw "To nie jest funkcja";
		if (n<1 or n>5)
			throw n;
	}
	catch(char const* s)
	{
		std::cerr << s << std::endl;
	}
	catch(int m)
	{
		std::cout << "Nie ma takiej funkcji" << std::endl;
	}
}

void Obsluga::Dalej()
{
	do
	{
	Kursor++;
	if (Kursor==Menu.ZbiorWyborow.end())
		Kursor=Menu.ZbiorWyborow.begin();
	}while((*Kursor)->hidden());
}

void Obsluga::Usun()
{
	try
	{
		int n=(*Kursor)->JakiStopienZagniezdzenia();
		if (n==0)
			throw "Nie mozna usunac menu glownego";
		delete *Kursor;
		Kursor=Menu.ZbiorWyborow.erase(Kursor);
		while(Kursor!=Menu.ZbiorWyborow.end() && (*Kursor)->JakiStopienZagniezdzenia()>n)
		{
			delete *Kursor;
			Kursor=Menu.ZbiorWyborow.erase(Kursor);
		}
		if(Kursor==Menu.ZbiorWyborow.end())
		{
			Kursor=Menu.ZbiorWyborow.begin();
		}
	}
	catch(const char* s)
	{
		std::cerr << s << std::endl;
	}
}

void Obsluga::Wstecz()
{
	do
	{
	if (Kursor==Menu.ZbiorWyborow.begin())
		Kursor=Menu.ZbiorWyborow.end();
	Kursor--;	
	}while((*Kursor)->hidden());
}	

void Obsluga::Zwin()
{
	try
	{
		Wybor* wsk_wyb=(*Kursor);
		Podmenu* wsk_menu;
		if((wsk_menu=dynamic_cast<Podmenu*>(wsk_wyb))==NULL)
			throw "Nie mozna rozwinac funkcji";
		if(wsk_menu->empty())
			throw "Menu jest puste";
		int n=(*Kursor)->JakiStopienZagniezdzenia();
		Dalej();
		while((*Kursor)->JakiStopienZagniezdzenia()>n)
		{
			(*Kursor)->Ukryj();
			Dalej();
		}
		Wstecz();
	}
	catch(const char* s)
	{
		std::cerr << s << std::endl;
	}
}

void Obsluga::Rozwin()
{
	
	try
	{	Wybor* wsk_wyb=(*Kursor);
		Podmenu* wsk_menu;
		if((wsk_menu=dynamic_cast<Podmenu*>(wsk_wyb))==NULL)
			throw "Nie mozna rozwinac funkcji";
		if(wsk_menu->empty())
			throw "Menu jest puste";
		int n=(*Kursor)->JakiStopienZagniezdzenia();
		Kursor++;
		if (Kursor==Menu.ZbiorWyborow.end())
			Kursor=Menu.ZbiorWyborow.begin();
		while((*Kursor)->JakiStopienZagniezdzenia()>n)
		{
			(*Kursor)->Pokaz();
			Kursor++;
			if (Kursor==Menu.ZbiorWyborow.end())
				Kursor=Menu.ZbiorWyborow.begin();
		}
	}
	catch(const char* s)
	{
		std::cerr << s << std::endl;
	}
}

std::ostream& operator<<(std::ostream &ekran, Obsluga &m)
{
	m.Wypisz(ekran);
	return ekran;
}

void Obsluga::Wypisz(std::ostream &ekran)
{
	for (kursor it=Menu.ZbiorWyborow.begin(); it!=Menu.ZbiorWyborow.end(); it++)
	{
		if(!(*it)->hidden())
		{
			ekran << **it;
		if (Kursor==it)
			ekran << " ***";
		ekran << std::endl;}
	}
	ekran << std::endl;
}

void Obsluga::Wykonaj()
{
	try
	{
		Wybor* wsk_wyb=(*Kursor);
		Jednoznaczny* wsk_jedn;
		if((wsk_jedn=dynamic_cast<Jednoznaczny*>(wsk_wyb))==NULL)
			throw "To nie jest funkcja";
		if(wsk_jedn->wsk_fun==NULL)
			throw "Nie przypisano funkcji";
		wsk_jedn->wsk_fun();
	}
	catch(const char* s)
	{
		std::cout << s << std::endl;
	}
}

void Obsluga::Drukuj()
{
	move(0,0);
	for (kursor it=Menu.ZbiorWyborow.begin(); it!=Menu.ZbiorWyborow.end(); it++)
	{
		if(!(*it)->hidden())
		{
			if (Kursor==it)
				attron(A_REVERSE);
			(*it)->Drukuj();
			if (Kursor==it)
				attroff(A_REVERSE);
			printw("\n");
		}
	}
	printw("\n");
}
