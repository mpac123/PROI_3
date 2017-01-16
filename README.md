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
3. Po usunięciu elementu (elementów) Menu kursor wskazuje na następny obiekt.
4. Jeżeli Podmenu jest zwinięte, nie ma możliwości przejścia kursorem do któregokolwiek 
z zagnieżdżonych w nim Wyborów. W tym celu należy je najpierw rozwinąć.

# Struktura klas reprezentujących Menu

Lista klas w kolejności nadrzędności, tzn. klasa wymieniona jako pierwsza nie korzysta
z żadnej z innych klas, jest za to wykorzystywana przez klasy nadrzędne, w szczególności
przez klasę bezpośrednio nadrzędną, tzn. klasę o numerze 2.

1. Wybor
  - Jednoznaczny
  - Podmenu
2. Kolekcja
3. Obsluga
4. Interfejs

