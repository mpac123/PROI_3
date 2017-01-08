menu: main.cpp wybor.cpp wybor.h kolekcja.h kolekcja.cpp obsluga.h obsluga.cpp
	g++ -o menu main.cpp wybor.cpp kolekcja.cpp obsluga.cpp -I. -Wall

clean:
	rm menu -f
