/*
strcat 链接
    src
    dst
    另一种拷贝，dst[strlen(dst)]
安全问题
    strcpy strcat
    目的地没用足够的空间，尽可能不要使用
安全版本
    char *strncpy(char *restrict dst, const char *restrict src, size_t n)
    char *strncat(char *restrict s1, const char *restrict s2, size_t n);
    int strncmp(const char *s1,const char *s2, size_t n);

字符串搜索函数
    字符串找字符
        char *strchr(connst char *s, int c)
        char *strrchr(const char *s, int c)
        NULL 没找到
如何寻找第二个

字符串找字符串
*/

int main ()
{
    char s[] = "hello";
    char *p = strchr(s, 'l');
    p = strchr(p+1, 'l');
    printf("%s\n", p);

    return 0;
}