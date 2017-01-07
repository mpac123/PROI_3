#ifndef _KURSOR_H_
#define _KURSOR_H_

include "drzewo.h"

class Kursor
{
public:
	Wybor* klik;
	std::string nazwa;
	Drzewo D(nazwa);
	Kursor(std::string s) : nazwa(s), D(s) {klik=begin()};
	
	Wybor* begin();
	Wybor* end();
	
	bool CzyKoniec();
	
	
}
;

#endif
