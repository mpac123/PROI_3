#ifndef _WYBOR_H_
#define _WYBOR_H_

#include <string>
#include <iostream>

class Wybor
{
	friend class Kolekcja;
	friend class Obsluga;
public:
	Wybor(std::string s) : nazwa(s) {};
	virtual ~Wybor() {};
		int JakiStopienZagniezdzenia();
protected:
	std::string nazwa;
	int stopienZagniezdzenia;
	bool czyUkryty;
	void Ukryj() {czyUkryty=true;};
	void Pokaz() {czyUkryty=false;};
	bool hidden() {return czyUkryty;};


	void NadajStopienZagniezdzenia(int n);
	
	friend std::ostream& operator<<(std::ostream &ekran, Wybor &w);
	virtual void Wypisz(std::ostream &ekran) {};
};

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
