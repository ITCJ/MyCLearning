/*
错误
    含义错误
    语法错误
*/
#include <stdio.h>
int main() {
    printf("糖橙结\n");
    printf("糖\n橙结\n");
    printf("糖");
    printf("橙结\n");

    jolly();
    jolly();
    jolly();
    deny();

    getchar();
}

int jolly() {
    printf("For he's a jolly good fellow!\n");
    //同main, 用户函数也可嵌套
}

int deny() {
    printf("Which nobody can deny!\n");
}