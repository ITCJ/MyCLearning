#include <stdio.h>

int main ()
{
    const float PI = 3.14159;
    float r = 1.5;
    float h = 3;
    float C, S, S2, V, V2;

    C = 2*PI*r; 
    S = PI * r * r;
    S2 = 4 * PI * r * r;
    V = 4 * PI * r * r / 3;
    V2 = h * PI * r * r;
    C = (int)(C*100 + 0.5)/100.0;
    S = (int)(S*100 + 0.5)/100.0;
    S2 = (int)(S2*100 + 0.5)/100.0;
    V = (int)(V*100 + 0.5)/100.0;
    V2 = (int)(V2*100 + 0.5)/100.0;

    printf("%.2f %.2f %.2f %.2f %.2f", C, S, S2, V, V2);
    return 0;
}