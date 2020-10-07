#include <stdio.h>

int main () {
//faulse
    // int dhour = delay / 60 * 100;
    // int dmin = delay % 60;

    // printf("%d\n", now + dhour + dmin);

    int now, delay;
    scanf("%d%d", &now, &delay);

    int hour = now/100;
    int min = hour * 60 + now%100;
    int co = min + delay;
    int timeh = co/60;
    int timem = co%60;

    printf("%d", timeh*100 + timem);

    return 0;

}