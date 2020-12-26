/*
所在行的最大值
n行 m列

输入数组

找最大点
    对一个数判断 
        行最大 1
        列最大 1
        存储 本身 行 列
打印存储

*/


#include <stdio.h>
#include <stdlib.h>

void readNumber(int **vector, int n, int m);
void findNumber(int **vector, int n, int m, int *cache);

int main ()
{
    int n, m;
    int ** vector;
    int * cache;
    scanf("%d %d", &n, &m);

    vector = (int**)malloc(sizeof(int*) * n);
    cache =(int*)malloc(sizeof(int*) * n+m);

    for (size_t i = 0; i < n; i++)
    {
        vector[i] = (int*)malloc(sizeof(int) * m);
    }
    for (size_t i = 0; i < m+n; i++)
    {
        // cache[i] = (int*)malloc(sizeof(int) * 3);
        cache[i] = 0;
    }

    for(size_t j = 0; j<n; j++)
    {
        for (size_t i = 0; i < m; i++)
        {
            *(*(vector+j)+i) = 0;
            // *(*vector + j*i) = 0; 不是堆栈不能这样用
        }
    }


    readNumber(vector, n, m);
    findNumber(vector,  n, m, cache);



    return 0;
}

void readNumber(int **vector, int n, int m)
{
    for (size_t j = 0; j < n; j++)
    {
        for (size_t i = 0; i < m; i++)
        {
            scanf("%d", *(vector+j) + i );
        }    
    }
}

// void readNumber(int **vector, int n, int m)
// {

//     for (size_t i = 0; i < m*n; i++)
//     {
//         scanf("%d", (*vector+i) );
//     }    

// }

void findNumber(int **vector, int n, int m, int *cache)
{
    for(size_t i = 0; i< n; i++)
    {
        for(size_t j=0; j< m; j++)
        {
            if (cache[i] < *(*(vector+i)+j)) 
                cache[i] = *(*(vector+i)+j);
        }
    }

    for(size_t i = 0; i< m; i++)
    {
        for(size_t j=0; j< n; j++)
        {
            if (cache[n+i] < *(*(vector+j)+i)) 
                cache[n+i] = *(*(vector+j)+i);
        }
    }

    for(size_t i = 0; i<n; i++)
    {
        for(size_t j = 0; j<m; j++)
        {
            if (cache[i] == cache[n+j])
            {
                printf("%d %d %d\n", cache[i], i+1, j+1);
            }
            
        }
    }
}