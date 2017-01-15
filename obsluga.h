#ifndef _OBSLUGA_H_
#define _OBSLUGA_H_

#include "kolekcja.h"
class Obsluga
{
	public:
	Obsluga(std::string s);
	Kolekcja Menu;
	kursor Kursor;
	void DodajMenu(std::string s);
	void DodajWyborJedn(std::string s);
	void PrzypiszFunkcje(int n);
	void Usun();
	void Dalej();
	void Wstecz();
	void Wypisz(std::ostream &ekran);
	void Zwin();
	void Rozwin();
	void Wykonaj();
	friend std::ostream& operator<<(std::ostream &ekran, Obsluga &m);
	void Drukuj();
	
};

#endif
