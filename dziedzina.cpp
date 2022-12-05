#include <iostream>

using namespace std;

void sprawdzanie_dziedziny(int w, double *x_poczatkowe, double *x_koncowe, double *b, double *c, double *d)
{
    while(w == 3 && (*x_poczatkowe == 0 || *x_koncowe == 0))
    {
        if(*x_poczatkowe == 0)
        {
            while(*x_poczatkowe == 0)
            {
                cout<<"Podałeś argument(początkowy) spoza dziedziny (mianownik nie może być równy 0), podaj nowy: ";
                cin>>*x_poczatkowe;
            }
        }
        else if(*x_koncowe == 0)
        {
            while(*x_koncowe == 0)
            {
                cout<<"Podałeś argument(końcowy) spoza dziedziny(mianownik nie może być równy 0), podaj nowy: ";
                cin>>*x_koncowe;
            }
        }
    }

    while(w == 6 && (*x_poczatkowe <= 0 || *x_koncowe <= 0 || (*d == 2 && (*b < 0 || *b == 1)) || *c == 0))
    {
        if(*x_poczatkowe <= 0)
        {
            while(*x_poczatkowe <= 0)
            {
                cout<<"Podałeś argument(początkowy) spoza dziedziny(x > 0), podaj nowy: ";
                cin>>*x_poczatkowe;
            }
        }
        if(*x_koncowe <= 0)
        {
            while(*x_koncowe <= 0)
            {
                cout<<"Podałeś argument(końcowe) spoza dziedziny(x > 0), podaj nowy: ";
                cin>>*x_koncowe;
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

    // while(w == 8 && *c % 2 == 0 && ((*x_poczatkowe > 0 && *x_poczatkowe < 0) || (*x_poczatkowe < 0 && *x_koncowe > 0) || (*x_poczatkowe > 0 && *x_koncowe > 0 && *b < 0) || (*x_poczatkowe < 0 && *x_koncowe < 0 && *b > 0)))
    // {
    //     if(*x_poczatkowe > 0 && *x_poczatkowe < 0)
    //     {
    //         int sqrtwybor = 0;
    //         double
    //         {
    //             cout<<"Nie możemy mieć x o różnych znakach. Twoje *x_poczatkowe: "<<*x_poczatkowe<<", *x_koncowe: "<<*x_koncowe<<". Co chcesz zmienić:\n1.*x_poczatkowe.\n2.x_końcowe.: ";
    //             cin>>sqrtwybor;
    //         }while(!(sqrtwybor == 1 || sqrtwybor == 2));
            
            

    //     }
    // }
}