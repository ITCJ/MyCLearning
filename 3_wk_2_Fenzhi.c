#include <stdio.h>

//else 与最近的{}if 匹配
//缩进不表现嵌套关系
//级联的if-else if
    //分段函数
int main () 
{
    int f, x;
    if (x < 0) 
    {
        f = -1; //print%d
    } 
    else if (x == 0)
    {
        f = 0;  //print%d
    } 
    else
    {
        f = 2*x;    //printf%d
    }
    printf("%d", f);    //单一出口较好
//if 常见错误
    //忘记大括号
        // int salary;
        // if (age > 60)
        //     salary = salary * 1.0;
        //     printf("%f\n", salary);  
    //if 后面分号
    //错误使用 == =

//多路分支 switch-case
    //switch 运行特点，直接跳到目标case
        // switch () 
        // {
        //     case 常量:
        // }
    //只能是整数int
    //常数或表达式 C99
    //case 表示开始点（入口），直到break
    



    return 0;
}
