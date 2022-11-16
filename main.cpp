/*
Projekt i implementacja programu obliczającego całkę złożoną metodą trapezów, Michał Żuk 87604
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

// przykładowa funkcja 1/(x^2)
double funkcja(double x)
{
    return 1/(pow(x,2));
}

void obliczanie()
{
    const int N = 1000;
    double x_poczatkowe,x_koncowe,suma,dx;
    cout<<"Podaj x początkowe: ";
    cin>>x_poczatkowe;

    cout<<"Podaj x końcowe: ";
    cin>>x_koncowe;

    suma = 0;

    dx = (x_koncowe - x_poczatkowe) / N;

    for(int i = 1; i < N; i++)
        suma+=funkcja(x_poczatkowe + (i * dx));

    suma = (suma + (funkcja(x_poczatkowe) + funkcja(x_koncowe)) / 2 ) * dx;

    cout<<"Wartość całki wynosi: "<<suma;
}

void menu_glowne()
{
    int wybor = 0;
    
    cout<<"Program obliczjący całkę złożoną metodą trapezów.\n";

    cout<<"Menu główne.\n1.Oblicz całkę.\n2.Koniec.\n";

    cin>>wybor;

    if(wybor == 1)
        obliczanie();

    while(wybor!=2)
    {
        cout<<"\nMenu główne.\n1.Oblicz całkę.\n2.Koniec.\n";
        cin>>wybor;
        if(wybor == 1)
            obliczanie();
    }
}

int main()
{
    setlocale(LC_ALL,"Polish");
    menu_glowne();
    return 0;
}