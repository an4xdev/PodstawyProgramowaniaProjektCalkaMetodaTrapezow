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
// f(x) = a * e^(b * x)
double exp_f(double x, double *a, double *b)
{
    return *a * exp(x * *b);
}
// f(x) = a*sqrt[c](b*x)
double sqrt_f(double x, double *a, double *b, double *c)
{
    return *a * pow(*b * x, *c);
}
// f(x) = a*|b*x|
double modul(double x, double *a, double *b)
{
    return *a*fabs(*b * x);
}
// f(x) = a*tg(b*x)
double tg(double x, double *a, double *b)
{
    return sin_f(x, a, b)/cos_f(x, a, b);
}
//
double ctg(double x, double *a, double *b)
{
    return (double)1/tg(x, a, b);
}