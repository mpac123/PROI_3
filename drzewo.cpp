#include "drzewo.h"

Drzewo::Drzewo(std::string s)
{
	Podmenu p(s);
	Wezel w(p);
	w.NadajStopienZagniezdzenia(0);
	zbiorWezlow.push_back(Wezel(m));
}

void Drzewo::StworzWezel(Podmenu& m)
{
	Wezel w(m);
	w.NadajStopienZagniezdzenia(0);
	zbiorWezlow.push_back(Wezel(m));
}

void Drzewo::DodajMenu(std::string s, Wezel& w)
{
	Podmenu m(s);
	w.DodajWybor(&m)
}
