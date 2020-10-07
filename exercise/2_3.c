#include <stdio.h>

int main() {
    int putin;
    scanf("%d", &putin);

    int a, b, c, out;
    a = putin / 100;
    b = putin % 100 / 10;
    //法一 %100 / 10； 法二 /10 %10
    c = putin % 100 % 10;
    out = c*100 + b*10 + a;
    
    printf("%d", out);

    return 0;
}