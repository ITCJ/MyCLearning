/*
bool
    头文件后可以使用true false
逻辑运算
    ! 逻辑非
    && 逻辑与
    || 逻辑或

    表达区间
        4 < x < 6
        4<x && x<6
    大写字母
        c >= 'A' && c<='Z'
    注意
        !age<20 !与age单目先运算，一直为true

优先级

短路
    逻辑运算自左向右
     a && b
     若a不成立，b不执行，因此b的变量操作不会进行
     不要把复合赋值组合进表达式


条件运算符（不要用）
    count = (count > 20)?count - 10: count +10
    if (count > 20)
        count = count - 10;
    else
        count = count + 10;
优先级
嵌套条件表达式

逗号运算符
    i = 3+4,5+6;
    输出为 7
    i = (3+4,5+6);
    输出为11

在for 中使用
    for (i=10, j=5; i< 10; i++, j--);
*/