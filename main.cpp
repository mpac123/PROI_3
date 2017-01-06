#include "wybor.h"
#include "wezel.h"

void fun()
{
	std::cout << "Jestem funkcja ktora nic nie robi\n";
}

int main()
{
	Podmenu Pierwsze("Alfabet");
	Jednoznaczny Jej("Wybor");
	Jej.PrzypiszFunkcje(fun);
	
	Wezel W(Pierwsze);
	Podmenu D("HAHA");
	W.DodajWybor(&Jej);
	W.DodajWybor(&D);
	std::cout << W << std::endl;
}
