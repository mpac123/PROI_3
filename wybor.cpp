#include "wybor.h"

void Jednoznaczny::PrzypiszFunkcje(void (*wsk)())
{
	wsk_fun=wsk;
}

void Jednoznaczny::Wypisz(std::ostream &ekran)
{
	if (wsk_fun==NULL)
		ekran << "-> " << nazwa << ": funkcja nieaktywna" << std::endl; 
	else
		ekran << "->" << nazwa << std::endl;
}

void Podmenu::Wypisz(std::ostream &ekran)
{
	ekran << "| " << nazwa << std::endl;
}

std::ostream& operator<<(std::ostream &ekran, Wybor &p)
{
	p.Wypisz(ekran);
	return ekran;
}
