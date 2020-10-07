#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int inputsquare(int a,int b,int c,float s1);
float cacusquare(int a,int b,int c);
int main()
{
   int a[3];
   int i,j;
   float s1;
   srand((unsigned)time(NULL));
   for(;j!=1;)
   {  
    for(i=0;i<3;i++)
       a[i]=rand();
       if(a[0]+a[1]>a[2]&&a[0]+a[2]>a[1]&&a[1]+a[2]>a[0]&&a[0]!=0&&a[1]!=0&&a[2]!=0)
       j=1;
   }
   printf("已知道三角形的三条边分别为：");
   for(i=0;i<3;i++)     
   printf("%d,",a[i]*100/32767);
   printf("\n");
   printf("请输入该三角形的面积：");
   scanf("%f,&s1");
   if( inputsquare(a[0],a[1],a[2],s1))
    printf("恭喜你的分数为100分");
    else
        printf("很遗憾你的分数为0分");
        
return 0;
}


int inputsquare(int a,int b, int c,float S)
{
   float s2,s3;
   int i=0;
       s2=cacusquare(a,b,c);
    s3=(int)(S*10+0.5)/10.0;
   if(s3==S)
    i=1;
   return i;
}


float  cacusquare(int a,int b,int c)
{
float p=0,s;
p=(a+b+c)/2.0;
s=sqrt(p*(p-a)*(p-b)*(p-c));
return s*1.0;

}