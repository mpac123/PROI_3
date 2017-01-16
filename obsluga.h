#ifndef _OBSLUGA_H_
#define _OBSLUGA_H_

#include "kolekcja.h"
/**
 * Klasa obsługująca obiekt klasy Kolekcja. Potrafi modyfikować obiekty klasy Wybór,
 * przechowywane przez atrybut klasy Kolekcja. Umożliwia wykonywanie operacji na Kolekcji - dodawanie
 * Wyborów, zwijanie i rozwijanie Podmenu oraz swobodne poruszanie się po kolejnych Wyborach,
 * z uwzględnieniem omijania Wyborów ukrytych.
 * 
 * Klasa ma charakter uniwersalny, nie narzuca żadnego konkretnego interfejsu użytkownika.
 * Z powodzeniem jej metody mogą być wykorzystywane przy tworzeniu różnych interfejsów.
 */
class Obsluga
{
public:
	friend class Interfejs;
	Obsluga(std::string s);
	/**Metoda tworząca nowy obiekt typu Podmenu i dodająca go do listy ZbiorWyborow
	 * zaraz za elementej tej listy pokazywanym przez atrybut Kursor.
	 * <param name='s'>nazwa obiektu typu Podmenu</param>
	 */
	void DodajMenu(std::string s);
	/**Metoda tworząca nowy obiekt typu Jednoznaczny i dodająca go do listy ZbiorWyborow
	 * zaraz za elementej tej listy pokazywanym przez atrybut Kursor.
	 * <param name='s'>nazwa obiektu typu Jednoznaczny</param>
	 */
	void DodajWyborJedn(std::string s);
	/** 
	 * Przypisuje do odpowiedniego pola obiektu typu Jednoznaczny wskaźnik na funkcję,
	 * którą ma wywoływać ten Wybór.
	 * <param name='n'>numer funkcji, która ma zostać przypisana Wyborowi</param>
	 */
	void PrzypiszFunkcje(int n);
	/**
	 * Usuwa Wybór, na który aktualnie wskazuje Kursor wraz ze wszystkimi Wyborami zagnieżdżonymi.
	 * Kursor na koniec jest ustawiony na pierwszym kolejnym niezagnieżdżonym obiekcie.
	 */
	void Usun();
	/**
	 * Przesuwa kursor na kolejny element listy ZbiorWyborow. Uwzględnia fakt, że część elementów może
	 * być ukryta i pomija je. Gdy Kursor pokazuje na ostatni element, przesuwa go na początek.
	 */
	void Dalej();
	/**
	 * Przesuwa kursor na poprzedni element listy ZbiorWyborow. Uwzględnia fakt, że część elementów może
	 * być ukryta i pomija je. Gdy Kursor pokazuje na pierwszy element, przesuwa go na koniec.
	 */
	void Wstecz();
	/**
	 * Metoda wykorzystywana przez przeładowany operator<<
	 */
	void Wypisz(std::ostream &ekran);
	/**
	 * Metoda ukrywa wszystkie elementy Kolekcji zagnieżdżone w Podmenu.
	 * Jeżeli wywołane dla typu innego niż Podmenu, zgłasza wyjątek.
	 */
	void Zwin();
		/**
	 * Metoda pokazuje wszystkie elementy Kolekcji zagnieżdżone w Podmenu (jeżeli 
	 * były wcześniej ukryte). Jeżeli Podmenu nie jest zwinięte, zgłasza wyjątek.
	 * Jeżeli wywołane dla typu innego niż Podmenu, zgłasza wyjątek.
	 */
	void Rozwin();
	/**
	 * Metoda wywoływana dla obiektu klasy Jednoznaczny (dla każdego innego zgłasza wyjątek).
	 * Wywołuje funkcję przypisaną do Wyboru Jednoznacznego pokazywanego przez Kursor.
	 * Jeżeli funkcja nie została jeszcze przypisana, zgłasza wyjątek.
	 */
	void Wykonaj();
	friend std::ostream& operator<<(std::ostream &ekran, Obsluga &m);
	//void Drukuj();
	
	
	private:
	Kolekcja Menu;
	kursor Kursor;
	Wybor* wsk_kursor() {return *Kursor;};
	
};

#endif
