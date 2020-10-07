/*
数组
如何记录很多数

数组

定义数组
    <类型> 变量名称 [元素数量];
        int grades[100];
        double weitght[20];
    元素数量为整数
    C99以前元素数量为编译时确定的字面量（二级考试）
数组
    容器
    所有元素类型相同
    一旦创建不能改变大小
    数组中元素在内存中紧密依次排列
    a[2] = a[1] + 10;
    在赋值左边的叫左值
数组的单元
    下标或索引，下标从0开始计数
    最大 数组个数-1
有效下标范围
    不会检查是否越界
    可能造成崩溃
        segementation fault
    运气好可能没出错
    程序员应保证下标范围安全

    c语言函数进出原理
长度为0的数组
    int a[0];
    可以存在但无用


*/

#include <stdio.h>

int main ()
{
    int read, count, all = 0;
    int number [100]; //定义数组 从0开始存储 隐患，超过100
    scanf("%d", &read);

    while (read != -1)
    {
        number [count] = read;  //对数组元素赋值
        all += read;
        count++;
        scanf("%d", &read);  
    }
    if (count > 0)
    {
        printf("%f", 1.0*all/count);
        int i;
        for ( i = 0; i < count; i++) //遍历
        {
            if (number[i] > 1.0*all/count) //使用数组中的元素
            {
                printf("%d\n", number[i]);
            }
            
        }
    
    }
    
    


    return 0;
}