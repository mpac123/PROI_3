#ifndef _WYBOR_H_
#define _WYBOR_H_

#include <string>
#include <iostream>

class Wybor
{
	friend class Wezel;
public:
	Wybor(std::string s) : nazwa(s) {};
	virtual ~Wybor() {};
	std::string nazwa;
	friend std::ostream& operator<<(std::ostream &ekran, Wybor &w);
	virtual void Wypisz(std::ostream &ekran) {};
};

class Jednoznaczny : public Wybor
{
	friend class Wezel;
public:
	Jednoznaczny(std::string s) : Wybor(s) {wsk_fun=NULL;};
	~Jednoznaczny() {};
	void (*wsk_fun)();
	void PrzypiszFunkcje(void (*wsk)());
	void Wypisz(std::ostream &ekran);
};

class Podmenu : public Wybor
{
	friend class Wezel;
public:
	Podmenu(std::string s) : Wybor(s) {};
	~Podmenu() {};
	void Wypisz(std::ostream &ekran);
};

#endif
