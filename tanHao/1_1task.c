/*
π/2 = (2/1 x 2/3) x (4/3 x 4/5) x (6/5 x 6/7) x … x [2n/(2n-1)x2n/(2n+1)]

    for n=precision  n+=2

注意点 int double计算后是0
       前后比较算法
       scanf lf

*/
#include <stdio.h>
#include <math.h>

int main ()
{
    double prn = 1.0;
    double prn2 = 1.0;
    double prn3 = 1.0;
    int i=0;
    // double result [2] = {1.0,1.0};
    double result1 = 1.0;
    double result2 = 1.0;
    double result3 = 1.0;
    double e = 0;

    scanf("%lf", &e);

    // for (int i = 1; i < 65535; i++)
    // {
        
    // }
    while (1)
    {
        result1 *= ( (prn+1)/(prn) ) * ( (prn+1)/(prn+2) );
        prn2 = prn+1;
        result2 = result1 * ( (prn2+1)/(prn2) ) * ( (prn2+1)/(prn2+2) );
        prn3 = prn+2;
        result3 = result2 * ( (prn3+1)/(prn3) ) * ( (prn3+1)/(prn3+2) );
        prn+=2;
        i++;
        //printf("%f\n", result1);
        // if ( e-2.0*result1 > 2.0*result2-e && 2.0*result2-e < 2.0*result3-e )
        // {
        //     printf("%.9f %d", 2*result1, i);
        //     break;
        // }

        if ( e-2.0*result1 < 2.0*result2-e )
        {
            printf("%.9f %d", 2*result1, i);
            break;   
        }
        
    }


    return 0;
}