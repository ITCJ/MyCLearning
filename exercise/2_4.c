#include  <stdio.h> 
//BCD数
int main () {
    int x, origin;
    scanf("%d", &x);

    origin = x/16*10 + x%16;

    printf("%d", origin);
    //printf %x
    return 0;
}