/*
strcpy 效率提高影响巨大
    src拷贝到dst
    restrict表明src和dst不重叠(C99)
    返回dst
        为了能链起代码
*/
#include <stdio.h>
char* mycpy (char* dst, const char* src)
{
    int idx = 0;
    //数组版
    while(src[idx] != '\0')
    {
        dst[idx] = src[idx];
        idx++;
    }
    dst[idx] = '\0';
    return dst;
    //指针版本
    int ret;
    ret = dst;
    while(*src)
    {
        *dst++ = *src;++
        *dst = '\0';
    }

    while( *dst++ = *src++)
        ;
}

int main ()
{
    /*
    复制一个字符串
        char *dst = (char*)malloc(strlen(src) + 1); // +1 结尾的'\0'
        strcpy(dst,src);
    */
}