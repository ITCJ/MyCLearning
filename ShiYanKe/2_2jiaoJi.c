/*
两组整数
一个与多个比较
    if 符合 存储
    -1 结束
排序待输出结果
    两两比较

注意：20个数不计算-1，所以需要21宽度的数组
*/

#include <stdio.h>

void readNumber(int order,int data[][21]);
void compare(int num, int data[][21]);
void setOrder (int num, int data[][21]);

int main ()
{
    int data[3][21] = {0};

    readNumber(0,data);
    readNumber(1,data);

    compare(0, data);

    setOrder(2,data);

    int i = 0;
    while (data[2][i]!=-1)
    {
        printf("%d ", data[2][i]);
        i++;
    }
    

    return 0;
}

void readNumber(int order,int data[][21])
{
    int i = 0;
    do
    {
        scanf("%d", &data[order][i] );
        i++;
    }while(data[order][i-1] != -1 );

}

void compare(int num, int data[][21])
{
    int k = 0;
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (data[num][i] == data[num+1][j] )
            {
                data[num+2][k] = data[num][i];
                k++;
                break;
            }    
        } 
    }
}

void setOrder (int num, int data[][21])
{
    int width = 21;
    int cache;
    for (size_t i = 0; i < width; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            if (data[num][j+1] == -1)
            {
                break;
            }
            
            if ( data[num][j] > data[num][j+1] )
            {
                cache = data[num][j+1];
                data[num][j+1] = data[num][j];
                data[num][j] = cache;
            }
            
        }
        
    }
    

}