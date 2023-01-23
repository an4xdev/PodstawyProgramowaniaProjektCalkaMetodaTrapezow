#include "program.cpp"
int main()
{
    setlocale(LC_ALL, "Polish");
    int w = menu_glowne();
    int N = 0;
    double x_poczatkowe, x_koncowe, suma = 0, dx;
    double a, b, c, d;
    int stopien = -1;
    double *tab;
    wprowadzanie_zmiennych_funkcyjnych(w, &a, &b, &c, &d, &stopien);
    if (stopien != -1)
    {
        tab = new double[stopien];
        uzupelnij_wielomian(tab, stopien);
    }
    wprowadzanie_x(&N, &x_poczatkowe, &x_koncowe);

    sprawdzanie_dziedziny(w, &x_poczatkowe, &x_koncowe, &b, &c, &d);

    wpisanie_do_pliku_wzoru(w, a, b, c, d, stopien, tab);

    dx = (x_koncowe - x_poczatkowe) / N;

    suma = sumowanie(w, N, x_poczatkowe, x_koncowe, dx, &a, &b, &c, &d, tab, stopien);

    if (stopien != -1)
        delete[] tab;

    wyniki(suma, N, x_poczatkowe, x_koncowe);
    return 0;
}