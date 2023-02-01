#include "program.cpp"
int main()
{
    setlocale(LC_ALL, "Polish");
    int w = menu_glowne();
    Funkcja f;
    f.N = 0;
    f.suma = 0;
    f.stopien = -1;
    wprowadzanie_zmiennych_funkcyjnych(w, &f);
    if (f.stopien != -1)
    {
        f.tab = new double[f.stopien];
        uzupelnij_wielomian(&f);
    }
    wprowadzanie_x(&f);

    sprawdzanie_dziedziny(w, &f);

    wpisanie_do_pliku_wzoru(w, &f);

    f.dx = (f.x_koncowe - f.x_poczatkowe) / f.N;

    f.suma = sumowanie(w, &f);

    if (f.stopien != -1)
        delete[] f.tab;

    wyniki(&f);
    return 0;
}