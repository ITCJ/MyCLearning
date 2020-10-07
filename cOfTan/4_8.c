#include <stdio.h>

int main ()
{
    int score;
    scanf ("%d", &score);

    switch (score/10)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        printf("E");
        break;
    case 6:
        printf("D");
        break;
    case 7:
        printf("C");
        break;
    case 8:
        printf("B");
        break;
    case 9:
        printf("A");
        break;
    case 10:
        printf("A");
        break;
    }

    return 0;
}