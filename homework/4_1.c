/*
    201901512330    唐承捷  月薪13980   税后13202.60 税金777.40
    test1   4800    4800.00
    test2   5000    5000
    test3   8000    bug     7910
            17000   16010
            85000   64160   20840
            86000   64760   21240   400 = 1000 *0.4

    ...     


    //速算扣除数
        3 000   2 910    90
        12 000  8 100    900
        25 000  10 400   2 600
        35 000  
        3   12  25  35  55  80
        8   17  30  40  60  85
scanf
    salary -= 5000
    rest= - 80 000
    fee += rest*0.4

*/
#include <stdio.h>

int main ()
{
    int salary, rest, x;
    float fee = 0;
    
    scanf("%d", &salary);

    if (salary > 5000)
    {
        rest = salary - 5000;

        if (rest > 80000)
        {
            x = rest - 80000;
            fee += x * 0.4;
            rest -= x;
        }
        if (rest > 55000)
        {
            x = rest - 55000;
            fee += x * 0.35;
            rest -= x;
        }
        if (rest > 35000)
        {
            x = rest - 35000;
            fee += x * 0.3;
            rest -= x;
        }
        if (rest > 25000)
        {
            x = rest - 25000;
            fee += x * 0.25;
            rest -= x;
        }
        if (rest > 12000)
        {
            x = rest - 12000;
            fee += x * 0.2;
            rest -= x;
        }
        if (rest > 3000)
        {
            x = rest - 3000;
            fee += x * 0.1;
            rest -= x;
        }
        if (rest > 0)
        {
            x = rest;
            fee += x * 0.03;
            rest -= x;
        }
    }
    
    printf("工资%7.2f 税金%7.2f", salary-fee, fee);



    return 0;
}