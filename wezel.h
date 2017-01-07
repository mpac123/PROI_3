#ifndef _WEZEL_H_
#define _WEZEL_H_

#include "wybor.h"
#include <vector>

class Wezel
{
	friend class Drzewo;
public:
	Wezel(Podmenu* m) : klucz(m) {};
	void UsunGalezie();
	Podmenu* klucz;
	std::vector<Wybor*> galezie;
	bool czyUkryty;
	
	Wezel& operator=(const Wezel& w);
	
	int JakiStopienZagniezdzenia();
	int IleGalezi();
	bool empty();
	bool hidden();
	Podmenu* PodajKlucz() {return klucz;};
	void Ukryj() {czyUkryty=true;};
	void Pokaz() {czyUkryty=false;};
	void DodajWybor(Wybor* w);
	
	friend std::ostream& operator<<(std::ostream &ekran, const Wezel &w);
};

#endif
