/*
Projekt i implementacja programu obliczającego całkę złożoną metodą trapezów, Michał Żuk 87604 główny plik programu
*/
#include "program.cpp"
int main()
{
    // ustawienie polskich znaków
    setlocale(LC_ALL, "Polish");
    // zmienna w bedzie przetrzymywała rodzaj funkcji, który wybieramy z menu
    int w = menu_glowne();
    // struktura
    Funkcja f;
    f.N = 0;
    f.suma = 0;
    f.stopien = -1;
    // wprowadzamy zmienne a, b, c, d, stopien, które modyfikują podstawowe funkcje
    wprowadzanie_zmiennych_funkcyjnych(w, &f);
    // funkcja generująca/niszcząca tablicę dynamiczną do współczynników wielomianu
    tablica_wielomian(&f, true);
    // wprowadzanie x_koncowe, x_początkowe i ilość trapezów N
    wprowadzanie_x(&f);
    // sprawdzanie dziedziny dla niektórych z funkcji
    sprawdzanie_dziedziny(w, &f);
    // zapisanie wzoru do pliku
    wpisanie_do_pliku_wzoru(w, &f);
    // obliczenie dx, czyli odległości między kolejnymi punktami
    f.dx = (f.x_koncowe - f.x_poczatkowe) / f.N;
    // obliczenie całki
    f.suma = sumowanie(w, &f);
    // funkcja generująca/niszcząca tablicę dynamiczną do współczynników wielomianu
    tablica_wielomian(&f, false);
    // wypisanie na konsoli oraz zapisanie do pliku wartości całki
    wyniki(&f);
    return 0;
}