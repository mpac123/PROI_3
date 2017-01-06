menu: main.cpp wybor.cpp wybor.h wezel.cpp wezel.h
	g++ -o menu main.cpp wybor.cpp wezel.cpp -I. -Wall

clean:
	rm menu -f
