#include "wybor.h"
#include "kolekcja.h"
#include "obsluga.h"
#include "interfejs.h"
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
	M.DodajMenu("Do lazienki");
	M.Wstecz();
	M.DodajMenu("Do kuchni");
	M.DodajWyborJedn("Blaty kuchenne");
	M.Wstecz();
	M.DodajWyborJedn("Stolnice");
	M.Dalej();
	M.Dalej();
	M.DodajWyborJedn("Lustra");
	M.Wstecz();
	M.DodajWyborJedn("Kosze na bielizne");
	M.Dalej();
	M.Dalej();
	M.DodajMenu("Dla dziecka");
	M.Wstecz();
	M.DodajMenu("Dla nastolatka");
	Interfejs g;
	g.Program(M);

	return 0;
	
}
