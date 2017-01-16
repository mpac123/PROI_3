#ifndef _WYBOR_H_
#define _WYBOR_H_

#include <string>
#include <iostream>
/**
 * Klasa reprezentująca pojedynczy wybór. Z jej obiektów korzysta zaprzyjaźniona
 * klasa Kolekcja. Jest to klasa najbardziej podrzędna w strukturze klas programu.
 */
class Wybor
{
	friend class Kolekcja; //!Klasa bezpośrednio obsługująca obiekty klasy Wybór.
	friend class Obsluga; 
public:
	Wybor(std::string s) : nazwa(s) {};
	virtual ~Wybor() {};
protected:
	std::string nazwa;
	/**
	 * Informacja o stopniu zagnieżdżenia danego wyboru wewnątrz Kolekcji
	 * Wyborów. Zwracana przez metodę int JakiStopienZagniezdzenia().
	 * Modyfikowana z zewnątrz klasy poprzez metodę void NadajStopienZagniezdzenia(int n).
	 */
	int stopienZagniezdzenia;
	//!Funkcja zwracająca wartość całkowitą, oznaczającą stopień zagnieżdżenia obiektu.
	int JakiStopienZagniezdzenia();
	//!Zmienna logiczna: prawdziwa gdy wybór jest ukryty, np. na skutek zwinięcia Podmenu, w którym obiekt był zagnieżdżony.
	bool czyUkryty;
	//! Zmienna logiczna czyUkryty zmienia wartość na "prawda".
	void Ukryj() {czyUkryty=true;};
	//! Zmienna logiczna czyUkryty zmienia wartość na "fałsz".
	void Pokaz() {czyUkryty=false;};
	//! Metoda zwracająca wartość zmiennej czyUkryty.
	bool hidden() {return czyUkryty;};
	//!Metoda modyfikująca atrybut stopienZagniezdzenia.
	void NadajStopienZagniezdzenia(int n);
	friend std::ostream& operator<<(std::ostream &ekran, Wybor &w);
	//!Metoda używana przez zaprzyjaźnioną funkcję przeładowującą operator<<.
	virtual void Wypisz(std::ostream &ekran) {};
	//virtual void Drukuj() {};
};

/**
 * Klasa dziedzicząca z klasy Wybór. Obiekty tej klasy reprezentują Wybór 
 * Jednoznaczny. Poza polami i metodami dziedziczonymi, posiada swoje własne,
 * charakterystyczne dla siebie metody i pola związane z przypisywaniem
 * do wyborów jednoznacznych konkretnych funkcji.
 */
class Jednoznaczny : public Wybor
{
	friend class Kolekcja;
	friend class Obsluga;
public:
	Jednoznaczny(std::string s) : Wybor(s) {wsk_fun=NULL;};
	~Jednoznaczny() {};
private:
	//!Wskaźnik na funkcję, którą można wywołać danym Wyborem Jednoznacznym. Dopóki nie przypisano wartości, ma wartość NULL.
	void (*wsk_fun)();
	//!Przypisuje do wskaźnika wsk_fun adres funkcji, którą ma wywoływać ten Wybór Jednoznaczny.
	void PrzypiszFunkcje(void (*wsk)());
	//!Metoda wykorzystywana przez funkcję zaprzyjaźnioną przeładowującą operator<<.
	void Wypisz(std::ostream &ekran);
	//void Drukuj();
};
/**
 * Klasa dziedzicząca z klasy Wybór. Obiekty tej klasy reprezentują Podmenu - Wybór,
 * w którym można zagnieżdżać inne Wybory (o wyższym stopniu zagnieżdżenia).
 */
class Podmenu : public Wybor
{
	friend class Kolekcja;
	friend class Obsluga;
public:	
	Podmenu(std::string s) : Wybor(s) {};
	~Podmenu() {};
private:
	//!Zmienna logiczna przechowująca informację, czy pod Podmenu posiada Wybory zagnieżdżone.
	bool czyPusty;
	//!Metoda zwracająca zmienną czyPusty
	bool empty() {return czyPusty;};
	//!Metoda wykorzystywana przez funkcję zaprzyjaźnioną przeładowującą operator<<.
	void Wypisz(std::ostream &ekran);
	//void Drukuj();
};

#endif
