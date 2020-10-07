/*
字符数组
    char word[] = {'H','e','l','l','o','!'};
        这不是c字符串，不能做字符串运算
    char word[] = {'H','e','l','l','o','!','\0'};
        //最后的'\0'变成字符串

字符串
    以0（整数0）结尾的一串字符
        0 或'\0'一样的，但与'0'不同
    0标志字符串的结束，本身并不是字符串的一部分
        计算字符串长度不包括0
    字符串以数组的形式存在，以数组或指针的形式访问
        更多的是以指针的形式
    string.h有很多处理字符串的函数

字符串变量
    char *sir = "Hello";
    char word[] = "Hello";
    char line[10] = "Hello";//占据6个，结尾0

字符串常量、字面量
    "Hello"
    "Hello" 会被编译器变成一个字符数组放在某处
        这个字符数组的长度是6，结尾0表示结束
    两个相邻字符串自动连接
    printf("20200417:\
                Pandownload 作者被抓了")//会有tab
    printf("20200417:"
        "Pandownload 作者被抓了" )//连起来不让编译器太宽，程序员把屏幕竖起来

字符串
    C语言的字符串以数组的形态存在
        不能用运算符对字符串做运算
        通过数组的方式可以遍历字符串
    唯一特殊的地方是字符串字面量可以用来初始化字符数组
    标准库提供了一系列字符串函数

字符串"变"量
    s 是一个指针,初始化指向一个字符串常量
        由于这个常量所在的地方,所以实际上s是 const char* s,但
        由于历史的原因,编译器接受不带const的写法
        但是如果对s所指的字符串做写入会导致严重的后果
    如果需要修改字符串,应该用数组
        char s[] = "Hello,world!";//编译器自动将不可读""拷贝到数组

指针还是数组
    char* str = 
    char word[] = 
    数组:字符串在这里
        作为本地变量空间自动回收
    指针:字符串不知道在哪里
        //只读
        处理参数
        动态分配空间

    如果要构造一个字符串->数组
    如果要处理一个字符串->指针

char*是字符串?
    字符串可以表达char*的形式
    char*不一定是字符串
        本意是指向字符的指针,可能是指向字符的数组(如int*)
        只有当它所指的字符数组有结尾的0,才能说它所指的是字符串


字符串的输入输出

字符串的赋值
    char* t = "title";
    char *s;
    s = t;
    没有产生新的字符串，
    只是指针s指向t所指的字符串，对s的操作都是对t的操作
字符串输入输出
    char string[8];
    scanf("%s", string);
    scanf是不安全的，不知道读入内容的长度

    安全地输入%7s
常见错误
    char *string;
    scanf("%s", string);
    以为cahr*是字符串类型，定义了一个字符串类型地变量string就可以直接使用了。
    由于没有对string初始化为0，所以不一定运行出错。
    没有指向有效地址。
空字符串
    char buffer[100]="";
    这是一个空字符串， buffer[0]=='\0';
    char buffer[]="";这个长度只有1
字符串数组
    char **a;
    a是一个指针，指向另一个指针，哪个指针指向一个字符（串）；
    char a[][];
    char *a[];
程序参数
    int main(int argc, char const *argv[])
    argv[0]是命令本身
        当使用unix地符号链接时,反映符号链接的名字
        busybox
*/

#include <stdio.h>

int main ()
{
//字符串变量
    int i = 0;
    char *s = "Hello,world!";
    char *s2 = "Hello,world!";
    char s3[] = "Hello,world!";
    // s[0] = 'B';
    printf("i =%p\n", i);
    printf("s =%p\n", s);
    printf("s2=%p\n", s2);//内存地址小,s,s2指向相同的地方 //小空间 代码 只读
    printf("s3=%p\n", s3);
    s3[0] = 'B';
    
    printf("Here!s3[0]=%c", s3[0]);

    char word[8];
    char word2[8];
    scanf("%7s", &word);
    scanf("%7s", &word2);//%s一个单词
    printf("%s##%s##", word, word2);//12345678

    int num;
    char *month[]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aus","Sep","Oct","Nov","Dec"};
    scanf("%d",&num);
    printf("%s\n",month[num-1]);


    return 0;
}