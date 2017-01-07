#include "wezel.h"


int Wezel::JakiStopienZagniezdzenia()
{
	return klucz->stopienZagniezdzenia;
}

int Wezel::IleGalezi()
{
	return galezie.size();
}

void Wezel::DodajWybor(Wybor* w)
{
	galezie.push_back(w);
}

void Wezel::UsunGalezie()
{
	if (galezie.size()>0)
	{
		std::cout<< "No cos tu usuwam ale najpierw wypisze" << std::endl;
		for(std::vector<Wybor*>::iterator it=galezie.begin(); it!=galezie.end(); ++it)
		{
			std::cout << **it << std::endl;
			delete *it;
		}
	}
}

Wezel& Wezel::operator=(const Wezel& w)
{
	if(&w==this)
		return *this;
	
	for(std::vector<Wybor*>::iterator it=galezie.begin(); it!=galezie.end(); ++it)
	{
		delete *it;
	}
	
	klucz=w.klucz;
	return *this;
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
