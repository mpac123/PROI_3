menu: main.cpp wybor.cpp wybor.h wezel.cpp wezel.h drzewo.cpp drzewo.h
	g++ -o menu main.cpp wybor.cpp wezel.cpp drzewo.cpp -I. -Wall

clean:
	rm menu -f
