/*
Projekt i implementacja programu obliczającego całkę złożoną metodą trapezów, Michał Żuk 87604 oddzielny plik z funkcjami
*/
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// f(x) = 1/(x^2)
double wykladnicza(double x, double *a, double *b, double *c)
{
    return *a/(*b*(pow(x,*c)));
}
// f(x) = a*sin(b*x)
double sin_f(double x, double *a, double *b)
{
    double temp = x * M_PI / 180;
    return *a*sin(*b*temp);
}
// f(x) = a*cos(b*x)
double cos_f(double x, double *a, double *b)
{
    double temp = x * M_PI / 180;
    return *a*cos(*b*temp);
}
// f(x) = a_n * x^n + a_n-1 * x^n-1 |+ ...
double wielomian(double x, double *a, int s)
{
    double temp = 0;
    for(int i = 0; i < s; i++)
    {
        temp += a[i] * pow(x, i);
    }
    return temp;
}
// f(x) = a * b^x
double potegowa(double x, double *a, double *b)
{
    return *a*pow(*b, x);
}
// f(x) = a * log_b(c * x) || a * log_e(c * x)
double logarytm(double x, double *a, double *b, double *c, double *d)
{
    if(*d == 1)
        return *a*log(x * *c);
    else 
    {
        return *a * (log10(*c * x) / log10(*b));
    }
}

void obliczanie(int w)
{
    int N = 0;
    double x_poczatkowe,x_koncowe,suma,dx;
    suma = 0;

    double *a,*b,*c,*d;
    int stopien = 0;

    switch(w)
    {
        case 1:
            cout<<"Podaj a (a*sin(b*x)): ";
            a = new double;
            cin>>*a;
            cout<<"Podaj b (a*sin(b*x)): ";
            b = new double;
            cin>>*b;
        break;
        case 2:
            cout<<"Podaj a (a*cos(x)): ";
            a = new double;
            cin>>*a;
            cout<<"Podaj b cos(b*x): ";
            b = new double;
            cin>>*b;
        break;
        case 3:
            cout<<"Podaj a (a/b*x^c): ";
            a = new double;
            cin >> *a;
            cout<<"Podaj b (a/b*x^c): ";
            b = new double;
            cin >> *b;
            cout<<"Podaj c (a/b*x^c): ";
            c = new double;
            cin >> *c;
        break;
        case 4:
            cout<<"Podaj stopień wielomianu: ";
            cin>>stopien;
            stopien++;
            a = new double [stopien];
            for(int i = stopien - 1; i >= 0; i--)
            {
                cout<<"Podaj a"<<i<<": ";
                cin>>a[i];
            }
        break;
        case 5:
            cout<<"Podaj a (a*(b^x)): ";
            a = new double;
            cin>>*a;
            cout<<"Podaj b (a*(b^x)): ";
            b = new double;
            cin>>*b;
        break;
        case 6:
            d = new double;
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
            a = new double;
            cin>>*a;
            if(*d == 2)
            {
                cout<<"Podaj b (a*log_b(c*x)): ";
                b = new double;
                cin>>*b;
            }
            cout<<"Podaj c (a*log_";
            if(*d == 1)
                cout<<"e: ";
            else 
                cout<<"b";
            cout<<"(c*x): ";
            c = new double;
            cin>>*c;
        break;
    }

    cout<<"Podaj ilość trapezów: ";
    cin>>N;
    while(N < 1)
    {
        cout<<"Podałeś złą ilość trapezów, min 1, podaj nową ilość: ";
        cin>>N;
    }

    cout<<"Podaj x początkowe: ";
    cin>>x_poczatkowe;

    cout<<"Podaj x końcowe: ";
    cin>>x_koncowe;

    if(w == 3 & (x_poczatkowe == 0 || x_koncowe == 0))
    {
        if(x_poczatkowe == 0)
        {
            while(x_poczatkowe == 0)
            {
                cout<<"Podałeś argument(początkowy) spoza dziedziny (mianownik nie może być równy 0), podaj nowy: ";
                cin>>x_poczatkowe;
            }
        }
        else if(x_koncowe == 0)
        {
            while(x_koncowe == 0)
            {
                cout<<"Podałeś argument(końcowy) spoza dziedziny(mianownik nie może być równy 0), podaj nowy: ";
                cin>>x_koncowe;
            }
        }
    }

    if(w == 6 && (x_poczatkowe < 0 || x_koncowe < 0 || (*d == 2 && (*b < 0 || *b == 1)) || *c == 0))
    {
        if(x_poczatkowe < 0)
        {
            while(x_poczatkowe < 0)
            {
                cout<<"Podałeś argument(początkowy) spoza dziedziny(x > 0), podaj nowy: ";
                cin>>x_poczatkowe;
            }
        }
        if(x_koncowe < 0)
        {
            while(x_koncowe < 0)
            {
                cout<<"Podałeś argument(końcowe) spoza dziedziny(x > 0), podaj nowy: ";
                cin>>x_koncowe;
            }
        }
        if(*d == 2 && (*b < 0 || *b == 1))
        {
            while(*b < 0 || *b == 1)
            {
                cout<<"Podałeś złą podstawę (b > 0 i b != 1): ";
                cin>>*b;
            }
        }
        if(*c == 0)
        {
            while(*c == 0)
            {
                cout<<"Argument w logarytmie nie może być mnożony przez 0, podaj nowe c: ";
                cin>>*c;
            }
        }
    }

    dx = (x_koncowe - x_poczatkowe) / N;

    for(int i = 1; i < N; i++)
    {
        switch(w)
        {
            case 1:
                suma += sin_f(x_poczatkowe + (i * dx), a, b);
            break;
            case 2:
                suma += cos_f(x_poczatkowe + (i * dx), a, b);
            break;
            case 3:
                suma += wykladnicza(x_poczatkowe + (i * dx), a, b, c);
            break;
            case 4:
                suma += wielomian(x_poczatkowe + (i * dx), a, stopien);
            break;
            case 5:
                suma += potegowa(x_poczatkowe + (i * dx), a, b);
            break;
            case 6:
                suma += logarytm(x_poczatkowe + (i * dx), a, b, c ,d);
            break;
        }
    }
        
    switch(w)
    {
        case 1:
            suma = (suma + (sin_f(x_poczatkowe, a, b) + sin_f(x_koncowe, a, b)) / 2 ) * dx;
        break;
        case 2:
            suma = (suma + (cos_f(x_poczatkowe, a, b) + cos_f(x_koncowe, a, b)) / 2 ) * dx;
        break;
        case 3:
            suma = (suma + (wykladnicza(x_poczatkowe, a, b, c) + wykladnicza(x_koncowe, a, b, c)) / 2 ) * dx;
        break;
        case 4:
            suma = (suma + (wielomian(x_poczatkowe, a, stopien) + wielomian(x_koncowe, a, stopien)) / 2 ) * dx;
        break;
        case 5:
            suma = (suma + (potegowa(x_poczatkowe, a, b) + potegowa(x_koncowe, a, b)) / 2 ) * dx;
        break;
        case 6:
            suma = (suma + (logarytm(x_poczatkowe, a, b, c, d) + logarytm(x_koncowe, a, b, c, d)) / 2 ) * dx;
        break;
    }
    
    delete a,b,c,d;

    cout<<"Wartość całki wynosi: "<<suma;
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
            cout<<"Jaki rodzaj funkcji:\n1.Sin(x).\n2.Cos(x)\n3.Wykładnicza: a/b*x^c.\n4.Wielomian.\n5.Potęgowa a*(b^x).\n6.Logarytm a*log_b(c*x).\n";
            int w2 = 0;
            cin>>w2;
            obliczanie(w2);
        }
    }while(wybor!=2);
}