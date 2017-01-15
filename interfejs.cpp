#include "interfejs.h"
#include <cstring>
void Interfejs::Program()
{
	initscr();
	
	int x, y;
	getmaxyx(stdscr,y,x);
	move(0,x);
	printw("Podaj nazwe menu: ");
	char* c;
	getstr(c);
	std::string s(c);
	Obsluga M(s);
	M.Drukuj();
	getch();
	endwin();
	delete c;
}
