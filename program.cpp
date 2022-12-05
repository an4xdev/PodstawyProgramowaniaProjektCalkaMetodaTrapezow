/*
Projekt i implementacja programu obliczającego całkę złożoną metodą trapezów, Michał Żuk 87604 oddzielny plik z funkcjami
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "funkcje.cpp"
#include "dziedzina.cpp"

using namespace std;

bool czy_mniejsze(double xp, double xk);

void wprowadzanie_x(int *N, double *x_poczatkowe, double *x_koncowe);

void uzupelnij_wielomian(double *t, int stopien);

void wprowadzanie_zmiennych_funkcyjnych(int w, double *a, double *b, double *c, double *d, int *stopien);

double sumowanie(int w, int N, double x_poczatkowe, double x_koncowe, double dx, double *a, double *b, double *c, double *d, double *tab, int stopien);

void wpisanie_do_pliku_wzoru(int w, double a, double b, double c, double d, int stopien, double *tab);

void obliczanie(int w);

void menu_glowne();

void obliczanie(int w)
{
    int N = 0;
    double x_poczatkowe,x_koncowe,suma,dx;
    suma = 0;

    double a,b,c,d;
    int stopien = -1;
    double *tab;

    wprowadzanie_zmiennych_funkcyjnych(w, &a, &b, &c, &d, &stopien);
    if(stopien!=-1)
    {
        tab = new double[stopien];
        uzupelnij_wielomian(tab, stopien);
    }

    wprowadzanie_x(&N, &x_poczatkowe, &x_koncowe);

    sprawdzanie_dziedziny(w, &x_poczatkowe, &x_koncowe, &b, &c, &d);

    wpisanie_do_pliku_wzoru(w, a, b, c ,d, stopien, tab);

    dx = (x_koncowe - x_poczatkowe) / N;

    suma = sumowanie(w, N, x_poczatkowe, x_koncowe, dx, &a, &b, &c, &d, tab, stopien);
    
    if(stopien!=-1)
        delete [] tab;

    cout<<"Wartość całki wynosi: "<<suma;
    fstream plik;

    plik.open("wyniki.txt", ios::app);

    if(!plik.good())
    {
        cout<<"Nie udało się otworzyć pliku.";
        exit(-1);
    }
    plik<<"Po zastosowaniu wzoru: suma = (suma + (f("<<x_poczatkowe<<") + f("<<x_koncowe<<")) / 2) * dx["<<N<<"]\n";
    plik<<"Wartość całki wynosi: "<<suma;
    plik.close();
}

void wprowadzanie_zmiennych_funkcyjnych(int w, double *a, double *b, double *c, double *d, int *stopien)
{
    switch(w)
    {
        case 1:
            cout<<"Podaj a (a*sin(b*x)): ";
            cin>>*a;
            cout<<"Podaj b (a*sin(b*x)): ";
            cin>>*b;
        break;
        case 2:
            cout<<"Podaj a (a*cos(x)): ";
            cin>>*a;
            cout<<"Podaj b cos(b*x): ";
            cin>>*b;
        break;
        case 3:
            cout<<"Podaj a (a/b*x^c): ";
            cin >> *a;
            cout<<"Podaj b (a/b*x^c): ";
            cin >> *b;
            cout<<"Podaj c (a/b*x^c): ";
            cin >> *c;
        break;
        case 4:
            cout<<"Podaj stopień wielomianu: ";
            cin>>*stopien;
            (*stopien)++;
        break;
        case 5:
            cout<<"Podaj a (a*(b^x)): ";
            cin>>*a;
            cout<<"Podaj b (a*(b^x)): ";
            cin>>*b;
        break;
        case 6:
            do 
            {
                cout<<"Podaj rodzaj logarytmu.\n1.Logarytm naturalny.\n2.Logarytm o innej podstawie: ";
                cin >> *d;
            }while (!(*d == 1 || *d == 2));
            cout<<"Podaj a (a*log_";
            if(*d == 1)
                cout<<"e: ";
            else 
                cout<<"b";
            cout<<"(c*x): ";
            cin>>*a;
            if(*d == 2)
            {
                cout<<"Podaj b (a*log_b(c*x)): ";
                cin>>*b;
            }
            cout<<"Podaj c (a*log_";
            if(*d == 1)
                cout<<"e: ";
            else 
                cout<<"b";
            cout<<"(c*x): ";
            cin>>*c;
        break;
        case 7:
            cout<<"Podaj a (a * e^(b*x)): ";
            cin>>*a;
            cout<<"Podaj b (a * e^(b*x)): ";
            cin>>*b;
        break;
        case 8:
            cout<<"Podaj a (a * sqrt c stopnia(b * x)): ";
            cin>>*a;
            cout<<"Podaj b (a * sqrt c stopnia(b * x)): ";
            cin>>*b;
            cout<<"Podaj stopień c (a * sqrt c stopnia(b * x)): ";
            cin>>*c;
        break;
    }
}

double sumowanie(int w, int N, double x_poczatkowe, double x_koncowe, double dx, double *a, double *b, double *c, double *d, double *tab, int stopien)
{
    fstream plik;

    plik.open("wyniki.txt", ios::app);

    if(!plik.good())
    {
        cout<<"Nie udało się otworzyć pliku.";
        exit(-1);
    }
    double wynik;
    double s = 0;
    for(int i = 1; i < N; i++)
    {
        wynik = 0;
        switch(w)
        {
            case 1:
                wynik = sin_f(x_poczatkowe + (i * dx), a, b);
                plik<<"Suma przed: "<<s<<", wartość funkcji: "<<wynik;
                s += wynik;
                plik<<", suma po: "<<s<<"\n";
            break;
            case 2:
                wynik = cos_f(x_poczatkowe + (i * dx), a, b);
                plik<<"Suma przed: "<<s<<", wartość funkcji: "<<wynik;
                s += wynik;
                plik<<", suma po: "<<s<<"\n";
            break;
            case 3:
                wynik = wykladnicza(x_poczatkowe + (i * dx), a, b, c);
                plik<<"Suma przed: "<<s<<", wartość funkcji: "<<wynik;
                s += wynik;
                plik<<", suma po: "<<s<<"\n";
            break;
            case 4:
                wynik = wielomian(x_poczatkowe + (i * dx), tab, stopien);
                plik<<"Suma przed: "<<s<<", wartość funkcji: "<<wynik;
                s += wynik;
                plik<<", suma po: "<<s<<"\n";
            break;
            case 5:
                wynik = potegowa(x_poczatkowe + (i * dx), a, b);
                plik<<"Suma przed: "<<s<<", wartość funkcji: "<<wynik;
                s += wynik;
                plik<<", suma po: "<<s<<"\n";
            break;
            case 6:
                wynik = logarytm(x_poczatkowe + (i * dx), a, b, c ,d);
                plik<<"Suma przed: "<<s<<", wartość funkcji: "<<wynik;
                s += wynik;
                plik<<", suma po: "<<s<<"\n";
            break;
            case 7:
                wynik = exp_f(x_poczatkowe + (i * dx), a, b);
                plik<<"Suma przed: "<<s<<", wartość funkcji: "<<wynik;
                s += wynik;
                plik<<", suma po: "<<s<<"\n";
            break;
        }
    }
        
    switch(w)
    {
        case 1:
            s = (s + (sin_f(x_poczatkowe, a, b) + sin_f(x_koncowe, a, b)) / 2 ) * dx;
        break;
        case 2:
            s = (s + (cos_f(x_poczatkowe, a, b) + cos_f(x_koncowe, a, b)) / 2 ) * dx;
        break;
        case 3:
            s = (s + (wykladnicza(x_poczatkowe, a, b, c) + wykladnicza(x_koncowe, a, b, c)) / 2 ) * dx;
        break;
        case 4:
            s = (s + (wielomian(x_poczatkowe, tab, stopien) + wielomian(x_koncowe, tab, stopien)) / 2 ) * dx;
        break;
        case 5:
            s = (s + (potegowa(x_poczatkowe, a, b) + potegowa(x_koncowe, a, b)) / 2 ) * dx;
        break;
        case 6:
            s = (s + (logarytm(x_poczatkowe, a, b, c, d) + logarytm(x_koncowe, a, b, c, d)) / 2 ) * dx;
        break;
        case 7:
            s = (s + (exp_f(x_poczatkowe, a, b) + exp_f(x_koncowe, a, b)) / 2 ) * dx;
        break;
    }
    plik.close();
    return s;
}

void menu_glowne()
{
    int wybor = 0;
    
    cout<<"Program obliczjący całkę złożoną metodą trapezów.\n";

    do
    {
        cout<<"\nMenu główne.\n1.Oblicz całkę.\n2.Koniec.\n";
        cin>>wybor;
        if(wybor == 1)
        {
            cout<<"Jaki rodzaj funkcji:\n1.Sin(x).\n2.Cos(x)\n3.Wykładnicza: a/b*x^c.\n4.Wielomian.\n5.Potęgowa a*(b^x).\n6.Logarytm a*log_b(c*x).\n7.Potęgowa a*e^(b*x).\n8.Pierwiastek a * sqrt c stopnia(b * x).\n";
            int w2 = 0;
            cin>>w2;
            obliczanie(w2);
        }
    }while(wybor!=2);
}

void wpisanie_do_pliku_wzoru(int w, double a, double b, double c, double d, int stopien, double *tab)
{
    fstream plik;

    plik.open("wyniki.txt", ios::out);

    if(!plik.good())
    {
        cout<<"Nie udało się otworzyć pliku.";
        exit(-1);
    }

    plik<<"Twój wzór funkcji: ";

    switch(w)
    {
        case 1:

            plik<<a<<"*sin("<<b<<"*x)";
        break;
        case 2:
            plik<<a<<"*cos("<<b<<"*x)";
        break;
        case 3:
            plik<<a<<"/"<<b<<"*x^"<<c;
        break;
        case 4:
            for(int i = stopien - 1; i >= 0; i--)
            {
                plik<<tab[i]<<"*x^"<<i;
                if(i!=0)
                    plik<<"+";
            }
        break;
        case 5:
            plik<<a<<"*"<<b<<"^x";
        break;
        case 6:
            plik<<a<<"*log_";
            if(d == 1)
                plik<<"e: ";
            else 
                plik<<b;
            plik<<"("<<c<<"*x)";
        break;
        case 7:
            plik<<a<<"*e^("<<b<<"*x)";
        break;
        case 8:
            plik<<a<<"*sqrt "<<c<<" stopnia("<<b<<"*x)";
        break;
    }
    plik<<'\n';
    plik.close();
}

bool czy_mniejsze(double xp, double xk)
{
    if(xp<=xk)
        return true;
    return false;
}

void wprowadzanie_x(int *N, double *x_poczatkowe, double *x_koncowe)
{
    cout<<"Podaj ilość trapezów: ";
    cin>>*N;
    while(*N < 1)
    {
        cout<<"Podałeś złą ilość trapezów, min 1, podaj nową ilość: ";
        cin>>*N;
    }

    cout<<"Podaj x początkowe: ";
    cin>>*x_poczatkowe;

    cout<<"Podaj x końcowe: ";
    cin>>*x_koncowe;

    while(!czy_mniejsze(*x_poczatkowe, *x_koncowe))
    {
        cout<<"Podałeś mniejsze x_koncowe niż x_początkowe, podaj nowe: ";
        cin>>*x_koncowe;
    }
}

void uzupelnij_wielomian(double *t, int stopien)
{
    for(int i = stopien - 1; i >= 0; i--)
    {
        cout<<"Podaj a"<<i<<": ";
        cin>>t[i];
    }
}