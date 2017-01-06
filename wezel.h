#ifndef _WEZEL_H_
#define _WEZEL_H_

#include "wybor.h"
#include <vector>

class Wezel
{
	friend class Drzewo;
public:
	Wezel(Podmenu& m) : klucz(m) {czyUkryty=true;};
	Podmenu& klucz;
	std::vector<Wybor*> galezie;
	bool czyUkryty;
	int stopienZagniezdzenia;
	
	int JakiStopienZagniezdzenia();
	void NadajStopienZagniezdzenia(int n);
	int IleGalezi();
	void Ukryj() {czyUkryty=true;};
	void Pokaz() {czyUkryty=false;};
	void DodajWybor(Wybor* w);
	
	friend std::ostream& operator<<(std::ostream &ekran, const Wezel &w);
};

#endif
