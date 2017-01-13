#include "wybor.h"
#include "kolekcja.h"
#include "obsluga.h"
void fun1();
void fun2();
void fun3();
void fun4();
void fun5();
int main()
{
	Obsluga M("Meble");
	M.DodajMenu("Do pokoju");
	M.Wstecz();
	//M.Wypisz();
	M.DodajMenu("Do lazienki");
	M.Wstecz();
	//M.Wypisz();
	//M.Wstecz();
	//M.Wypisz();
	M.DodajMenu("Do kuchni");
	M.DodajWyborJedn("Blaty kuchenne");
	//M.Wstecz();
	M.PrzypiszFunkcje(5);
	
	//M.Usun();
	M.Wypisz();
	
}
