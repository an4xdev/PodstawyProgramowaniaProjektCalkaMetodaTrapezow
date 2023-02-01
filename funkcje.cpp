/*
Projekt i implementacja programu obliczającego całkę złożoną metodą trapezów, Michał Żuk 87604 oddzielny plik z funkcjami matematycznymi i sprawdzaniem dziedziny
*/
#include <cmath>
#include <iostream>
#include "struktura.h"

using namespace std;

// f(x) = 1/(x^2)
double wykladnicza(double x, Funkcja *f)
{
    return f->a / (f->b * (pow(x, f->c)));
}
// f(x) = a*sin(b*x)
double sin_f(double x, Funkcja *f)
{
    double temp = (x * M_PI) / 180;
    return f->a * sin(f->b * temp);
}
// f(x) = a*cos(b*x)
double cos_f(double x, Funkcja *f)
{
    double temp = x * M_PI / 180;
    return f->a * cos(f->b * temp);
}
// f(x) = a_n * x^n + a_n-1 * x^n-1 |+ ...
double wielomian(double x, Funkcja *f)
{
    double temp = 0;
    for (int i = 0; i < f->stopien; i++)
    {
        temp += f->tab[i] * pow(x, i);
    }
    return temp;
}
// f(x) = a * b^x
double potegowa(double x, Funkcja *f)
{
    return f->a * pow(f->b, x);
}
// f(x) = a * log_b(c * x) || a * log_e(c * x)
double logarytm(double x, Funkcja *f)
{
    if (f->d == 1)
        return f->a * log(x * f->c);
    else
    {
        return f->a * (log10(f->c * x) / log10(f->b));
    }
}
// f(x) = a * e^(b * x)
double exp_f(double x, Funkcja *f)
{
    return f->a * exp(x * f->b);
}
// f(x) = a*sqrt[c](b*x)
double sqrt_f(double x, Funkcja *f)
{
    return f->a * pow(f->b * x, 1.0 / f->c);
}
// f(x) = a*|b*x|
double modul(double x, Funkcja *f)
{
    return f->a * fabs(f->b * x);
}
// f(x) = a*tg(b*x)
double tg(double x, Funkcja *f)
{
    return sin_f(x, f) / cos_f(x, f);
}
//
double ctg(double x, Funkcja *f)
{
    return (double)1 / tg(x, f);
}

void sprawdzanie_dziedziny(int w, Funkcja *f)
{
    while (w == 3 && (f->x_poczatkowe == 0 || f->x_koncowe == 0))
    {
        if (f->x_poczatkowe == 0)
        {
            while (f->x_poczatkowe == 0)
            {
                cout << "Podałeś argument(początkowy) spoza dziedziny (mianownik nie może być równy 0), podaj nowy: ";
                cin >> f->x_poczatkowe;
            }
        }
        else if (f->x_koncowe == 0)
        {
            while (f->x_koncowe == 0)
            {
                cout << "Podałeś argument(końcowy) spoza dziedziny(mianownik nie może być równy 0), podaj nowy: ";
                cin >> f->x_koncowe;
            }
        }
    }

    while (w == 6 && (f->x_poczatkowe <= 0 || f->x_koncowe <= 0 || (f->d == 2 && (f->b < 0 || f->b == 1)) || f->c == 0))
    {
        if (f->x_poczatkowe <= 0)
        {
            while (f->x_poczatkowe <= 0)
            {
                cout << "Podałeś argument(początkowy) spoza dziedziny(x > 0), podaj nowy: ";
                cin >> f->x_poczatkowe;
            }
        }
        if (f->x_koncowe <= 0)
        {
            while (f->x_koncowe <= 0)
            {
                cout << "Podałeś argument(końcowe) spoza dziedziny(x > 0), podaj nowy: ";
                cin >> f->x_koncowe;
            }
        }
        if (f->d == 2 && (f->b < 0 || f->b == 1))
        {
            while (f->b < 0 || f->b == 1)
            {
                cout << "Podałeś złą podstawę (b > 0 i b != 1): ";
                cin >> f->b;
            }
        }
        if (f->c == 0)
        {
            while (f->c == 0)
            {
                cout << "Argument w logarytmie nie może być mnożony przez 0, podaj nowe c: ";
                cin >> f->c;
            }
        }
    }

    while (w == 8 && (int)f->c % 2 == 0 && ((f->b < 0 && (f->x_poczatkowe > 0 || f->x_koncowe > 0)) || (f->b > 0 && (f->x_poczatkowe < 0 || f->x_koncowe < 0))))
    {
        if (f->b < 0 && (f->x_poczatkowe > 0 || f->x_koncowe > 0))
        {
            while (f->x_poczatkowe > 0 || f->x_koncowe > 0)
            {
                while (f->x_poczatkowe > 0)
                {
                    cout << "Twoje x_początkowe nie znajduje się w dziedzinie funkcji(musi być mniejsze od 0), podaj nowe: ";
                    cin >> f->x_poczatkowe;
                }
                while (f->x_koncowe > 0)
                {
                    cout << "Twoje x_koncowe nie znajduje się w dziedzinie funkcji(musi być mniejsze od 0), podaj nowe: ";
                    cin >> f->x_koncowe;
                }
            }
        }
        if (f->b > 0 && (f->x_poczatkowe < 0 || f->x_koncowe < 0))
        {
            while (f->x_poczatkowe < 0 || f->x_koncowe < 0)
            {
                while (f->x_poczatkowe < 0)
                {
                    cout << "Twoje x_poczatkowe nie znajduje się w dziedzinie funkcji(musi być większe od 0), podaj nowe: ";
                    cin >> f->x_poczatkowe;
                }
                while (f->x_koncowe < 0)
                {
                    cout << "Twoje x_koncowe nie znajduje się w dziedzinie funkcji(musi być większe od 0), podaj nowe: ";
                    cin >> f->x_koncowe;
                }
            }
        }
    }
}