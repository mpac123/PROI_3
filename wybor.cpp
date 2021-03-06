#include "wybor.h"

void Jednoznaczny::PrzypiszFunkcje(void (*wsk)())
{
	wsk_fun=wsk;
}

void Jednoznaczny::Wypisz(std::ostream &ekran)
{
	for (int i=0; i<stopienZagniezdzenia; i++)
	{
		ekran << "  ";
	}
	if (wsk_fun==NULL)
		ekran << "-> " << nazwa << ": funkcja nieaktywna" << std::endl; 
	else
		ekran << "->" << nazwa << std::endl;
}

int Wybor::JakiStopienZagniezdzenia()
{
	return stopienZagniezdzenia;
}

void Wybor::NadajStopienZagniezdzenia(int n)
{
	stopienZagniezdzenia=n;
}

void Podmenu::Wypisz(std::ostream &ekran)
{
	for (int i=0; i<stopienZagniezdzenia; i++)
	{
		ekran << "  ";
	}
	ekran << "| " << nazwa << std::endl;
}

std::ostream& operator<<(std::ostream &ekran, Wybor &p)
{
	p.Wypisz(ekran);
	return ekran;
}
