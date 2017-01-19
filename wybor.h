#ifndef _WYBOR_H_
#define _WYBOR_H_

#include <string>
#include <iostream>
/**
 * Klasa reprezentująca pojedynczy wybór - jest klasą bazową dla klas reprezentujących
 * wybory jednoznaczne i podmenu . Z jej obiektów korzysta zaprzyjaźniona
 * klasa Kolekcja. 
 * Klasa przechowuje takie informacje o wyborze, jak jego nazwa czy stopień zagnieżdżenia.
 */
class Wybor
{
	friend class Kolekcja;
	friend class Obsluga; 
public:
	Wybor(std::string s) : nazwa(s) {};
	virtual ~Wybor() {};
protected:
	std::string nazwa;
	int stopienZagniezdzenia;
	int JakiStopienZagniezdzenia();
	bool czyUkryty;
	void Ukryj() {czyUkryty=true;};
	void Pokaz() {czyUkryty=false;};
	bool hidden() {return czyUkryty;};
	void NadajStopienZagniezdzenia(int n);
	friend std::ostream& operator<<(std::ostream &ekran, Wybor &w);
	virtual void Wypisz(std::ostream &ekran) {};
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
	void (*wsk_fun)();
	void PrzypiszFunkcje(void (*wsk)());
	void Wypisz(std::ostream &ekran);
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
	bool czyPusty;
	bool empty() {return czyPusty;};
	void Wypisz(std::ostream &ekran);
};

#endif
