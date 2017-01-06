#include "wezel.h"

int Wezel::JakiStopienZagniezdzenia()
{
	return stopienZagniezdzenia;
}

void Wezel::NadajStopienZagniezdzenia(int n)
{
	stopienZagniezdzenia=n;
}

int Wezel::IleGalezi()
{
	return galezie.size();
}

void Wezel::DodajWybor(Wybor* w)
{
	galezie.push_back(w);
}

std::ostream& operator<<(std::ostream &ekran, const Wezel &w)
{
	ekran << w.klucz;
	for (size_t i=0; i<w.galezie.size(); i++)
	{
		ekran << " " << (*w.galezie[i]);
	}
	return ekran;
}
