#include "wybor.h"
#include "kolekcja.h"
#include "obsluga.h"

void fun()
{
	std::cout << "Jestem funkcja ktora nic nie robi\n";
}

int main()
{
	Obsluga M("Meble");
	M.DodajMenu("Do pokoju");
	M.Wypisz();
	M.DodajMenu("Do lazienki");
	M.Wypisz();
	M.Wstecz();
	M.Wypisz();
	M.DodajMenu("Do kuchni");
	M.Wypisz();
	
}
