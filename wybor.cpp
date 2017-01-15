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
		ekran << "-> " << nazwa << ": funkcja nieaktywna"; 
	else
		ekran << "->" << nazwa;
}

void Jednoznaczny::Drukuj()
{
	for (int i=0; i<stopienZagniezdzenia; i++)
	{
		printw(" ");
	}
	if (wsk_fun==NULL)
		printw("->%s: funkcja nieaktywna",nazwa.c_str());
	else
		printw("->%s",nazwa.c_str());
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
	ekran << "| " << nazwa << " ";
	if (!empty())
	{
		ekran << "|";
	}
}

void Podmenu::Drukuj()
{
	for (int i=0; i<stopienZagniezdzenia; i++)
	{
		printw(" ");
	}
	attron(A_BOLD);
	printw("| %s",nazwa.c_str());
	if (!empty())
	{
		printw(" |");
	}
	attroff(A_BOLD);
}

std::ostream& operator<<(std::ostream &ekran, Wybor &p)
{
	p.Wypisz(ekran);
	return ekran;
}
