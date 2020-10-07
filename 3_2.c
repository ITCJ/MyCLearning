//数
#include <stdio.h>

int main () {
//进制
    int example;
    example =10000;

    printf("example in ten is %d, in eight is %o, in 16 is %x \n", example ,example ,example);
    printf("also example in ten is %#d in eight is %#o in 16 is %#x " ,example , example, example);

//其他整数类型
    int a;
    short int b;
    long int c;
    long long int d;
    unsigned int e;
    unsigned long int f;

//字符

    printf("\a");
    printf("\a");
    printf("\a");
    printf("\a");
    printf("\a");
    
    char ch;
    printf("Please enter a character:");
    scanf("%c", &ch);
    
    printf("The code for %c is %d.\n", ch, ch);

// 可移植型 stdint.h inttypes.h
        
//浮点





    return 0;
}

