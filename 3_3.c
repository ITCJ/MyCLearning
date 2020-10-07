//类型大小 sizeof
#include <stdio.h>

int main () {
    printf("Type int has a size if %zd bytes.\n", sizeof(int));

//参数和陷阱
    int n = 4;
    int m = 5;
    float f = 7.5;
    float g =8.5;

    printf("%d\n", n , m);
    printf("%d %d %d\n", n);
    printf("%d %d %d \n", n, f, g);

//转义序列
float salary;
printf("\a输入你想要的每月薪水：");
printf("______元元元元元元\b\b\b\b\b\b");
    //c中下划线是0.5个字符_,汉字1个
scanf("%f", &salary);
printf("\n\t%.2f元每个月，%.2f每年", salary, salary*12.0);
printf("\rGee!\n");
    //\r 回到起始 \t tab
return 0;
}