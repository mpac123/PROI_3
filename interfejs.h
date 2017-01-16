#ifndef _INTERFEJS_H_
#define _INTERFEJS_H_
/**
 * Klasa reprezentująca interfejs użytkownika. Menu wyświetlane jest 
 * w terminalu w następujący umówny sposób:
 * - Poziom zagnieżdżenia reprezentowany jest ilością spacji
 * - Pozycja Kursora pokazywana jest symbolem ***
 * - Lista dostępnych poleceń wyświetlana jest bezpośrednio pod Menu.
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
