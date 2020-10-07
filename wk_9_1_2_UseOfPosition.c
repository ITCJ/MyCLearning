/*
应用场景

交换两个变量的值
    由于函数无法影响变量的值，故使用变量无法做交换

返回多个值
    某些只能通过指针带回
    传入的参数实际上是需要保存带回结果的变量
    返回值只能返回一个

传入函数的数组
传入函数的数组组成了什么
    函数参数表void minmax(int a[],)
        是个指针
    可以用数组运算符[]进行运算

一下四种函数原型是等价的
    int sum(int *ar, int n)
    int sum(int *, int)
    int sum(int ar[], int n)
    int sum(int [], int )

数组变量是特殊的指针
    数组变量本身表达地址
        int a[10]; int *p = a; //无需用&取地址
    数组的单元表达是变量，需要取地址
        a == &a[0]
    []运算符可以对数组做，也可以对指针做
        p[0]  a[0]

    int min[1]指针   min[0]
数组间不能直接赋值
int b[]   - --- int *const b

C99 指针与const
指针是const
    int *const q = &i; //q是const
    *q = 26; //OK
    q++; // ERROR
所指是const
    const int *p = &i;
    *p = 26; //error *p 是const
    i = 26; //ok
    p = &j; //ok

    int i;
    const int* p1 = &i;
    int const* p2 = &i;
    int *const p3 = &i;
    const 在 * 前后

转换
    总是可以把非const 转const
    void f(const int *x);
    int a = 15;
    f(&a);  //ok
    const int b = a;

    f(&b);  //ok
    b = a + 1; //error
    传递的参数的类型比地址大，这是常用手段：既能用比较少的
    字节数传递值给参数，又能避免函数对外面变量的修改

const数组
    const int a[] = {1,2,3,4,5,6}
    数组变量已经是const 的指针，这里的const 表示每个数组单元都是const int
    必须通过初始化赋值

保护数组值
    数组传入函数传递的是地址，股函数内部可以修改数组的值
    保护数组不被破坏，可以设置参数const
    int sum(const int a[], int length);
    

*/