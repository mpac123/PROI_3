#ifndef _DRZEWO_H_
#define _DRZEWO_H_

#include "wezel.h"
#include "list.h"

class Drzewo
{
public:
	Drzewo(std::string s);
	~Drzewo();
	std::list<Wezel> zbiorWezlow;
	void StworzWezel(Podmenu* m);
	void DodajMenu(std::string s, Wezel& w);
	void DodajWybor(std::string s, Wezel& w);
	
	
};

#endif
