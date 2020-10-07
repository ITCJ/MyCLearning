#include <stdio.h>
//change
int main (){
    int money =0;
    int price =0;
    int change =0;
    const int ABC=0; //常量大写
//初始化/赋值的差异
    printf("请输入你付的钱：______元\b\b\b\b");
    scanf("%d", &money);

    printf("\n请输入你的购买额:______元\b\b\b\b");
    scanf("%d", &price);

    change = money - price;
    printf("找零为:%d元", change);
//scanf两次
    int a, b;
    printf("输入两个数：");
    scanf("%d %d", &a, &b);
    printf("%d + %d = %d", a, b, a+b);  
        //如果输入字符，scanf获取不到，a和b是原内存的数

    return 0;

}