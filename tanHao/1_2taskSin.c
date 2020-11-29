#include <stdio.h>
#include <math.h>

double accCum(int base, double x)
{
    double result = 1;

    for (int i = 1; i <= base; i++)
    {
        result *= x/i;
    }
    return result;
}
int main ()
{
    double x = 0.0;
    double sin = 0.0;
    int y = 1;
    int count = 1;
    int n;
    scanf("%lf %d", &x, &n);
    sin = x;

    while ( count < n)
    {
        y+=2;
        double ass[2] = {1,-1}; 
        // double up = pow(x,y);
        // double down = (1.0 * accCum(y));
        // double result = up/down;
        sin += ass[count%2] * accCum(y, x);
        count ++;
    }
    
    printf("%.8f", sin, n);

    return 0;
}