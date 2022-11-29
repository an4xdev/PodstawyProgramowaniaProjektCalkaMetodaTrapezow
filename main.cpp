/*
Projekt i implementacja programu obliczającego całkę złożoną metodą trapezów, Michał Żuk 87604
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

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

double wielomian(double x, double *a, int s)
{
    double temp = 0;
    for(int i = 0; i < s; i++)
    {
        temp += a[i] * pow(x, i);
    }
    return temp;
}

void obliczanie(int w)
{
    const int N = 1000;
    double x_poczatkowe,x_koncowe,suma,dx;
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
                cout<<"Podałeś argument(początkowy) spoza dziedziny, podaj nowy: ";
                cin>>x_poczatkowe;
            }
        }
        else if(x_koncowe == 0)
        {
            while(x_koncowe == 0)
            {
                cout<<"Podałeś argument(końcowy) spoza dziedziny, podaj nowy: ";
                cin>>x_koncowe;
            }
        }
    }

    suma = 0;

    dx = (x_koncowe - x_poczatkowe) / N;

    double *a,*b,*c;
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
            for(int i = 0; i < stopien; i++)
            {
                cout<<"Podaj a"<<i<<" :";
                cin>>a[i];
            }
        break;
    }

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
    }
    
    delete a,b,c;

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
            cout<<"Jaki rodzaj funkcji:\n1.Sin(x).\n2.Cos(x)\n3.Wykładnicza: a/b*x^c.\n4.Wielomian.\n";
            int w2 = 0;
            cin>>w2;
            obliczanie(w2);
        }
    }while(wybor!=2);
}

int main()
{
    setlocale(LC_ALL,"Polish");
    menu_glowne();
    return 0;
}