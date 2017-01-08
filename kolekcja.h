#ifndef _KOLEKCJA_H_
#define _KOLEKCJA_H_

#include "wybor.h"
#include <list>

typedef std::list<Wybor*>::iterator kursor;
class Kolekcja
{
	friend class Obsluga;
	Kolekcja(std::string s);
	~Kolekcja();
	std::string nazwa;
	std::list<Wybor*> ZbiorWyborow;
	
	void DodajMenu(std::string, kursor& it);
	void DodajWyborJedn(std::string, kursor& it);
	
};

#endif

