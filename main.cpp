#include "wybor.h"
#include "wezel.h"
#include "drzewo.h"

void fun()
{
	std::cout << "Jestem funkcja ktora nic nie robi\n";
}

int main()
{
	/*Podmenu Pierwsze("Alfabet");
	Jednoznaczny Jej("Wybor");
	Jej.PrzypiszFunkcje(fun);
	
	Wezel W(Pierwsze);
	Podmenu D("HAHA");
	W.DodajWybor(&Jej);
	W.DodajWybor(&D);
	std::cout << W << std::endl;*/
	
	Drzewo M("Meble");
	M.DodajMenu("Do salonu", M.zbiorWezlow[0]);
	M.DodajMenu("Do kuchni", M.zbiorWezlow[0]);
	M.DodajWybor("Lodowki", M.zbiorWezlow[2]);
	M.DodajMenu("Eleganckie", M.zbiorWezlow[1]);
	
	std::cout << M.zbiorWezlow.size() << std::endl;
	
}
