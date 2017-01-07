#include "drzewo.h"

Drzewo::Drzewo(std::string s)
{
	Podmenu* p=new Podmenu(s);
	p->NadajStopienZagniezdzenia(0);
	Wezel w(p);
	w.Pokaz();
	zbiorWezlow.push_back(w);
}

Drzewo::~Drzewo()
{
	delete zbiorWezlow[0].klucz;
	for (std::list<Wybor*>::iterator i=zbiorWezlow.begin(); i<zbiorWezlow.end(); i++)
	{
		zbiorWezlow[i].UsunGalezie();
	}
}

void Drzewo::StworzWezel(Podmenu* m)
{
	Wezel w(m);
	w.Ukryj();
	zbiorWezlow.push_back(w);
}

void Drzewo::DodajMenu(std::string s, Wezel& w)
{
	Podmenu* m=new Podmenu(s);
	m->NadajStopienZagniezdzenia(w.JakiStopienZagniezdzenia()+1);
	w.DodajWybor(m);
	StworzWezel(m);
}

void Drzewo::DodajWybor(std::string s, Wezel& w)
{
	Jednoznaczny* j=new Jednoznaczny(s);
	j->NadajStopienZagniezdzenia(w.JakiStopienZagniezdzenia()+1);
	w.DodajWybor(j);
}

//std::ostream& operator<<(std::ostream &ekran, Drzewo &p)
