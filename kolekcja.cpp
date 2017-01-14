#include "kolekcja.h"

Kolekcja::Kolekcja(std::string s) : nazwa(s) 
{
	Podmenu* p=new Podmenu(s);
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
	Wybor* wsk_wyb=(*it);
	Podmenu* wsk_menu;
	if((wsk_menu=dynamic_cast<Podmenu*>(wsk_wyb))==NULL)
		throw "To jest wybor jednoznaczny - nie mozna dodac menu";
	wsk_menu->czyPusty=0;
	Podmenu* p=new Podmenu(s);
	p->czyPusty=1;
	p->Pokaz();
	p->NadajStopienZagniezdzenia((*it)->JakiStopienZagniezdzenia()+1);
	it=ZbiorWyborow.insert(++it,p);
}

void Kolekcja::DodajWyborJedn(std::string s, kursor& it)
{
	Wybor* wsk_wyb=(*it);
	Podmenu* wsk_menu;
	if((wsk_menu=dynamic_cast<Podmenu*>(wsk_wyb))==NULL)
		throw "To jest wybor jednoznaczny - nie mozna dodac innego wyboru";
	wsk_menu->czyPusty=0;
	Jednoznaczny* j=new Jednoznaczny(s);
	j->NadajStopienZagniezdzenia((*it)->JakiStopienZagniezdzenia()+1);
	j->Pokaz();
	it=ZbiorWyborow.insert(++it,j);
}
