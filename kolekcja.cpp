#include "kolekcja.h"

Kolekcja::Kolekcja(std::string s) : nazwa(s) 
{
	Podmenu* p=new Podmenu(s,1);
	p->Pokaz();
	p->czyPusty=1;
	p->NadajStopienZagniezdzenia(0);
	ZbiorWyborow.push_back(p);
}

Kolekcja::~Kolekcja()
{
	for (kursor it=ZbiorWyborow.begin(); it!=ZbiorWyborow.end(); it++)
	{
		delete *it;
	}
}

void Kolekcja::DodajMenu(std::string s, kursor& it)
{
	//(*it)->czyPusty=0;
	Podmenu* p=new Podmenu(s,1);
	p->czyPusty=1;
	p->Pokaz();
	p->NadajStopienZagniezdzenia((*it)->JakiStopienZagniezdzenia()+1);
	it=ZbiorWyborow.insert(it++,p);
}

void Kolekcja::DodajWyborJedn(std::string s, kursor& it)
{
	//(*it)->czyPusty=0;
	Jednoznaczny* j=new Jednoznaczny(s,0);
	j->NadajStopienZagniezdzenia((*it)->JakiStopienZagniezdzenia()+1);
	it=ZbiorWyborow.insert(it++,j);
}
