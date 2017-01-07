#include "wezel.h"


int Wezel::JakiStopienZagniezdzenia()
{
	return klucz->stopienZagniezdzenia;
}

int Wezel::IleGalezi()
{
	return galezie.size();
}

bool Wezel::empty()
{
	if (IleGalezi()==0)
		return true;
	return false;
}

bool Wezel::hidden()
{
	return czyUkryty;
}

void Wezel::DodajWybor(Wybor* w)
{
	galezie.push_back(w);
}

void Wezel::UsunGalezie()
{
	if (galezie.size()>0)
	{
		for(std::vector<Wybor*>::iterator it=galezie.begin(); it!=galezie.end(); ++it)
		{
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
