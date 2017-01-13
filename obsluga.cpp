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
	Menu.DodajMenu(s,Kursor);
}

void Obsluga::DodajWyborJedn(std::string s)
{
	Menu.DodajWyborJedn(s,Kursor);
}

void Obsluga::PrzypiszFunkcje(int n)
{
	//try
	//{
	std::list<Jednoznaczny*>::iterator k;
	if ((*k=dynamic_cast<Jednoznaczny*>(*Kursor)) != NULL)
	{
		std::cout << "lol\n";
	//if (n==1) (*k)->PrzypiszFunkcje((&fun1));
	//if (n==2) (*k)->PrzypiszFunkcje((&fun2));
	//if (n==3) (*k)->PrzypiszFunkcje((&fun3));
	//if (n==4) (*k)->PrzypiszFunkcje((&fun4));
	//if (n==5) (*k)->PrzypiszFunkcje((&fun5));
	}
	else
		throw "To nie jest wybor jednoznaczny";
	//}
	//catch(std::string s)
	//{
	//	std::cerr << s << std::endl;
	//}
}

void Obsluga::Dalej()
{
	if (Kursor==Menu.ZbiorWyborow.end())
		Kursor=Menu.ZbiorWyborow.begin();
	else 
		Kursor++;
}

void Obsluga::Usun()
{
	int n=(*Kursor)->JakiStopienZagniezdzenia();
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

void Obsluga::Wstecz()
{
	if (Kursor==Menu.ZbiorWyborow.begin())
		Kursor=Menu.ZbiorWyborow.end();
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
