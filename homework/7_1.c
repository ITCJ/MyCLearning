/*
668755
0251
668977

k   c
1   2
2   3

1 1 1 3 5 9 17 

N 
xyz=1
sum

*/

#include <stdio.h>

int main ()
{
    int N,sum,judge;
    int x,y,z;
    int i = 0;
    sum = 0;
    x = y = z = 1;
    

    scanf("%d", &N);

    for ( i = 0; i < N/3  ; i++)
    {
        sum += x +  y + z;
        printf("%12d %12d %12d", x, y ,z);
        if (i%2 == 1)   printf ("\n");
        
        x = x + y + z;
        y = y + z + x;
        z = z + x + y;
    }

    judge = N % 3;
    switch (judge)
    {
    case 0:                                                 break;
    case 1:     printf("%12d", x);          sum += x;       break;
    case 2:     printf("%12d %12d", x, y);  sum += x + y;   break;
    }
    
    printf("\n%d", sum);

    return 0;
}
