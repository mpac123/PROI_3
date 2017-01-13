#ifndef _WYBOR_H_
#define _WYBOR_H_

#include <string>
#include <iostream>

class Wybor
{
	friend class Kolekcja;
public:
	Wybor(std::string s, bool cM) : nazwa(s), czyMenu(cM) {};
	virtual ~Wybor() {};
		int JakiStopienZagniezdzenia();
protected:
	std::string nazwa;
	bool czyMenu;
	int stopienZagniezdzenia;


	void NadajStopienZagniezdzenia(int n);
	
	friend std::ostream& operator<<(std::ostream &ekran, Wybor &w);
	virtual void Wypisz(std::ostream &ekran) {};
};

class Jednoznaczny : public Wybor
{
	friend class Kolekcja;
	friend class Obsluga;
public:
	Jednoznaczny(std::string s, bool cM) : Wybor(s,cM) {wsk_fun=NULL;};
	~Jednoznaczny() {};
private:
	void (*wsk_fun)();
	void PrzypiszFunkcje(void (*wsk)());
	void Wypisz(std::ostream &ekran);
};

class Podmenu : public Wybor
{
	friend class Kolekcja;
public:	
	Podmenu(std::string s, bool cM) : Wybor(s,cM) {};
	~Podmenu() {};
private:
	bool czyUkryty;
	bool czyPusty;
	void Ukryj() {czyUkryty=true;};
	void Pokaz() {czyUkryty=false;};
	bool empty() {return czyPusty;};
	bool hidden() {return czyUkryty;};
	void Wypisz(std::ostream &ekran);
};

#endif
