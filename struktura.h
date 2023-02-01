/*
Projekt i implementacja programu obliczającego całkę złożoną metodą trapezów, Michał Żuk 87604 oddzielny plik z definicją struktury
*/
struct Funkcja
{
    int N;
    double x_poczatkowe, x_koncowe, suma, dx;
    double a, b, c, d;
    int stopien;
    double *tab;
};