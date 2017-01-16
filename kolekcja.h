#ifndef _KOLEKCJA_H_
#define _KOLEKCJA_H_

#include "wybor.h"
#include <list>

typedef std::list<Wybor*>::iterator kursor;
/**
 * Klasa zaprzyjaźniona z klasą Wybór i klasami pochodnymi, obsługująca 
 * obiekty tej klasy.
 */
class Kolekcja
{
public:
	friend class Obsluga;
	/**
	 * Konstruktor obiektu typu Kolekcja. Tworzy nowy obiekt klasy Podmenu, 
	 * zgodnie z założeniem, że każda Kolekcja musi posiadać jeden obiekt klasy Podmenu,
	 * o stopniu zagnieżdżenia 0, znajdujący się na początku listy ZbiórWyborow.
	 * <param name='s'>Nazwa Kolekcji, będąca jednocześnie nazwą obiektu Podmenu o stopniu
	 * zagnieżdżenia 0</param>
	 */
	Kolekcja(std::string s);
	~Kolekcja();
private:
	//!nazwa Kolekcji, będąca jednocześnie nazwą pierwszego elementu listy
	//!ZbiorWyborow - Wyboru o poziomie zagnieżdżenia 0.
	std::string nazwa;
	//!Lista przechowująca wskaźniki do obiektów typu Wybór. Kolejność 
	//!elementów na liście odpowiada kolejności wyświetlania elementów Menu.
	std::list<Wybor*> ZbiorWyborow;
	
	/**
	 * Metoda tworząca obiekt klasy Podmenu i dodająca do listy ZbiorWyborow wskaźnik do tego obiektu.
	 * <param name='s'>Nazwa obiektu klasy Podmenu</param>
	 * <param name='it'>Iterator wskazujący miejsce w liście ZbiórWyborow, za którym bezpośrednio
	 * dodany zostanie wskaźnik do obiektu klasy Podmenu</param>
	 */
	void DodajMenu(std::string s, kursor& it);
		/**
	 * Metoda tworząca obiekt klasy Jednoznaczny i dodająca do listy ZbiorWyborow wskaźnik do tego obiektu.
	 * <param name='s'>Nazwa obiektu klasy Jednoznaczny</param>
	 * <param name='it'>Iterator wskazujący miejsce w liście ZbiórWyborow, za którym bezpośrednio
	 * dodany zostanie wskaźnik do obiektu klasy Jednoznaczny</param>
	 */
	void DodajWyborJedn(std::string s, kursor& it);
	
};

#endif

