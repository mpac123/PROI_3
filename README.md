# Informacje o projekcie

# Polecenie

Menu programu okienkowego jest kolekcją wyborów. Każdy z wyborów jest albo
jednoznaczny albo wskazuje na inne menu. Oprogramować bibliotekę klas reprezentujących
menu. Biblioteka ma umożliwiać następujące czynności:
- Dodawanie/usuwanie wyborów jednoznacznych do/z (pod)menu.
- Dodawanie/usuwanie podmenu do/z (pod)menu.
- Przypisywanie wyborów jednoznacznych do pewnych funkcji.
- Rozwijanie/zwijanie podmenu.
- Dokonywanie wyborów jednoznacznych.
Napisać program, który wszystkie powyższe funkcjonalności udostępnia poprzez polecenia
wydawane z klawiatury. Przyjąć, że za wyborami jednoznacznymi może kryć się stały zbiór
funkcji wypisujący na konsoli komunikaty typu “Zadziałała funkcja nr 14”.

# Założenia
1. Menu zawsze musi się składać z conajmniej jednego Wyboru typu Podmenu. Nie można usunąć
takiego Podmenu.
2. Usunięcie Podmenu oznacza usunięcie razem z nim wszystkich zagnieżdżonych w nim Wyborów.
3. Po usunięciu elementu (elementów) Menu kursor wskazuje na poprzedni obiekt.
4. Po dodaniu nowego zagnieżdżonego Wyboru, kursos jest ustawiony na tym nowododanym Wyborze.
5. Jeżeli Podmenu jest zwinięte, nie ma możliwości przejścia kursorem do któregokolwiek 
z zagnieżdżonych w nim Wyborów. W tym celu należy je najpierw rozwinąć.

# Struktura klas reprezentujących Menu

Klasy użyte do zaprojektowania Menu:

1. Wybor
  - Jednoznaczny
  - Podmenu
2. Kolekcja
3. Obsluga
4. Interfejs

# Metody wykorzystywane w interfejsie użytkownika

Użytkownik dysponuje wieloma metodami, pozwalającymi na swobodne poruszanie się po Menu i zarządzanie nim.
Są to metody publiczne klasy Obsluga - w sekcji tej klasy szczegółowo opisano działanie i parametry każdej z metod.

# Sposób testowania

Za obsługę interfejsu tekstowego służącego do testowania programu odpowiada klasa Interfejs - szczegółowy opis klasy wraz z opisem jej metod publicznych znajduje
się w osobnej sekcji poświęconej tej klasie. 

## Sposób 1 - od zera
Po uruchomieniu programu użytkownik zostaje poproszony o podanie nazwy Menu - zostanie utworzone pierwsze Podmenu
o stopniu zagnieżdżenia 0. Następnie uzytkownik może poruszać się po Menu za pomocą klawiszy W (góra) i S (dół). Dodatkowe
opcje są zależne od tego, czy kursos pokazuje na Podmenu czy Wybór Jednoznaczny i wszystkie możliwe do użycia skróty wraz
z opisami są wypisane na ekranie bezpośrednio pod Menu. Taki sposób testowania umożliwia metoda publiczna klasy Interfejs 
Start().

## Sposób 2 - bazując na stworzonym Menu
Program można również uruchomić dla stworzonego wcześniej w interfejsie użytkownika Menu. Wówczas użytkownik nie musi wprowadzać
nazwy Menu - od razu można nawigować i zarządzać Menu w taki sam sposób, jak opisano dla sposobu 1. Taki sposób testowania
umozliwia metoda publiczna klasy Interfejs Program(Obsluga &M), gdzie obiekt M został wcześniej stworzony (i modyfikowany).

