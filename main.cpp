/*
Projekt i implementacja programu obliczającego całkę złożoną metodą trapezów, Michał Żuk 87604
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

// f(x) = 1/(x^2)
double wykladnicza(double x)
{
    return 1/(pow(x,2));
}
// f(x) = sin(x)
double sin_f(double x)
{
    double temp = x * M_PI / 180;
    return sin(temp);
}
// f(x) = cos(x)
double cos_f(double x)
{
    double temp = x * M_PI / 180;
    return cos(temp);
}

void obliczanie(int w)
{
    const int N = 1000;
    double x_poczatkowe,x_koncowe,suma,dx;
    cout<<"Podaj x początkowe: ";
    cin>>x_poczatkowe;

    cout<<"Podaj x końcowe: ";
    cin>>x_koncowe;

    double (*foo)(double);

    switch (w)
    {
    case 1:
        foo = sin_f;
        break;
    case 2:
        foo = cos_f;
        break;
    case 3:
        foo = wykladnicza;
    default:
        break;
    }

    suma = 0;

    dx = (x_koncowe - x_poczatkowe) / N;

    for(int i = 1; i < N; i++)
        suma += foo(x_poczatkowe + (i * dx));

    suma = (suma + (foo(x_poczatkowe) + foo(x_koncowe)) / 2 ) * dx;

    cout<<"Wartość całki wynosi: "<<suma;
}

void menu_glowne()
{
    int wybor = 0;
    
    cout<<"Program obliczjący całkę złożoną metodą trapezów.\n";

    do
    {
        cout<<"\n1Menu główne.\n1.Oblicz całkę.\n2.Koniec.\n";
        cin>>wybor;
        if(wybor == 1)
        {
            cout<<"Jaki rodzaj funkcji:\n1.Sin(x).\n2.Cos(x)\n3.1/x^2.\n";
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