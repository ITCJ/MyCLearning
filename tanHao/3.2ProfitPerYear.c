#include <stdio.h>

int main ()
{
    int found = 1000;
    
    double r1 = 0.0036;
    double r2 = 0.0225;
    double r3 = 0.0198;

    double p1,p2,p3;

    p1 = found * (1.0 + r1);
    p2 = found * (1.0 + r2);
    p3 = found * (1.0 + r3/2.0) * (1.0 + r3/2.0);

    printf("%f \n%f \n%f \n", p1, p2, p3);

    return 0;
}