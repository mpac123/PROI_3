menu: main.cpp wybor.cpp wybor.h kolekcja.h kolekcja.cpp obsluga.h obsluga.cpp interfejs.cpp interfejs.h
	g++ -o  menu main.cpp wybor.cpp kolekcja.cpp obsluga.cpp  interfejs.cpp -I. -Wall

clean:
	rm menu -f
