#ifndef _KOLEKCJA_H_
#define _KOLEKCJA_H_

#include "wybor.h"
#include <list>

typedef std::list<Wybor*>::iterator kursor;
/**
 * Klasa zaprzyjaźniona z klasą Wybór i klasami pochodnymi, obsługująca 
 * obiekty tej klasy. Wybory są przechowywane w liście ZbiorWyborow.
 * 
 * Zgodnie z założeniem, że każda Kolekcja musi posiadać jeden obiekt klasy Podmenu,
 * jej konstruktor tworzy nowy obiekt klasy Podmenu
 * o stopniu zagnieżdżenia 0 i dodaje go na początek listy ZbiórWyborow. Nazwa tego
 * obiektu klasy Podmenu jest jednocześnie nazwą całej kolekcji.
 */
class Kolekcja
{
public:
	friend class Obsluga;
	Kolekcja(std::string s);
	~Kolekcja();
private:
	std::string nazwa;
	std::list<Wybor*> ZbiorWyborow;
	void DodajMenu(std::string s, kursor& it);
	void DodajWyborJedn(std::string s, kursor& it);
	
};

#endif

