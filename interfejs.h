#ifndef _INTERFEJS_H_
#define _INTERFEJS_H_
/**
 * Klasa reprezentująca interfejs użytkownika. Menu wyświetlane jest 
 * w terminalu w następujący umówny sposób:
 * - Poziom zagnieżdżenia reprezentowany jest odpowiednim wcięciem.
 * - Pozycja Kursora pokazywana jest symbolem ***.
 * - Lista dostępnych poleceń wyświetlana jest bezpośrednio pod Menu.
 * - Podmenu reprezentowane jest zapisem: <b>| Nazwa podmenu </b>, gdy menu
 * nie posiada zagnieżdżonych obiektów lub <b>| Nazwa podmenu |</b>, gdy posiada zagnieżdżone
 * obiekty (w szczególności można je rozwinąć).
 * - Wybór jednoznaczny reprezentowany jest zapisem: <b>-> Nazwa wyboru</b>. Jeżeli do wyboru
 * nie została jeszcze przypisana żadna funkcja, po dwukropku znajduje się dopisek <b>funkcja nieaktywna</b>.
 */
#include "obsluga.h"
class Interfejs
{
	public:
	/**
	 * Funkcja umożliwiająca użytkownikowi stworzenie nowego Menu od zera. Pobiera
	 * z klawiatury informacje o Podmenu o stopniu zagnieżdżenia 0, niezbędnym
	 * do utworzenia nowego obiektu typu Obsluga, a następnie wywołuje funkcję Program(Obsluga& M).
	 */
	void Start();
	/**
	 * Metoda przetwarzająca polecenia uzytkownika. Może być wywołana dla stworzonego
	 * wcześniej obiektu typu Obsluga.
	 */
	void Program(Obsluga& M);
	private:
	void ZarzadzajPodmenu(std::string s, Obsluga& M);
	void ZarzadzajWyboremJedn(std::string s, Obsluga& M);
};


#endif
