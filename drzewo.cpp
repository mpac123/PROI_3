#include "drzewo.h"

Drzewo::Drzewo(std::string s)
{
	Podmenu* p=new Podmenu(s);
	p->NadajStopienZagniezdzenia(0);
	Wezel w(p);
	zbiorWezlow.push_back(w);
}

Drzewo::~Drzewo()
{
	delete zbiorWezlow[0].klucz;
	for (size_t i=0; i<zbiorWezlow.size(); i++)
	{
		zbiorWezlow[i].UsunGalezie();
	}
}

void Drzewo::StworzWezel(Podmenu* m)
{
	zbiorWezlow.push_back(Wezel(m));
}

void Drzewo::DodajMenu(std::string s, Wezel& w)
{
	Podmenu* m=new Podmenu(s);
	std::cout << "Tworze nowe menu: " << *m;
	m->NadajStopienZagniezdzenia(w.JakiStopienZagniezdzenia()+1);
	w.DodajWybor(m);
	StworzWezel(m);
}

void Drzewo::DodajWybor(std::string s, Wezel& w)
{
	Jednoznaczny* j=new Jednoznaczny(s);
	j->NadajStopienZagniezdzenia(-1);
	w.DodajWybor(j);
}

//std::ostream& operator<<(std::ostream &ekran, Drzewo &p)
