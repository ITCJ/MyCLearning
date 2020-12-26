#include <stdio.h>

double accCum(int base, double x)
{
    double result2 = 1;

    for (int i = 1; i <= base; i++)
    {
        result2 *= x/i;
    }
    return result2;
}

int main ()
{
    double x = 0.0;

    int count = 1;
    int n;
    scanf("%lf %d", &x, &n);
    double result = 0;

    for (int i = 0; i <= n; i++)
    {
        result += accCum(i, x);
    }
    
    printf("%f", result);
    return 0;
}