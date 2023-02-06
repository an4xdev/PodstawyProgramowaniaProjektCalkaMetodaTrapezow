/*
Projekt i implementacja programu obliczającego całkę złożoną metodą trapezów, Michał Żuk 87604 główny plik programu
*/
#include "program.cpp"
int main()
{
    setlocale(LC_ALL, "Polish");
    int w = -1;
    while (w != 3)
    {

        w = menu_glowne();
        switch (w)
        {
        case 1:
            obliczanie_calki();
            break;
        case 2:
            wypisanie_wynikow();
            break;
        }
    }
    return 0;
}