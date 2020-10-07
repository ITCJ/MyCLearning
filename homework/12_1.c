#include <stdio.h>

int triPlus (int end, int a[]);

int main ()
{
    int a[5] = {1, 2, 3, 0, 0};
    int b, x;

    printf("请输入你要算到哪个数:");
    scanf("%d", &x);
    b = triPlus(x, a);
    printf("%d", b);
    return 0;

}

int triPlus (int end, int a[])
{
    a[3] = a[0] * a[1] + a[2];
    if (a[4] == end)
    {
        return a[2];
    }
    else 
    {
        a[0] = a[1];
        a[1] = a[2];
        a[2] = a[3];
        a[4] ++;
        triPlus(end, a);
    }
}