/*
一元多项式相加

输入：系数个数+指数个数

二维数组 指数系数[]

for 数组个数
    if 指数==指数
        系数+系数

方法二：数据结构

*/
// #include <stdio.h>

// struct polynomial {
//     int coefficient;
//     int power;
// }


// int main ()
// {
//     int inputWidth; //输入数据的数量
//     scanf("%d", &inputWidth);
    

//     return 0;
// }


#include<stdio.h>
int main()
{
 int a[100],b[100];
 int c,d,l,m,n,i,j,k,t,x;
 scanf("%d",&n);
 l=n/2+1;
 for (i=1;i<=n/2;i++)
 scanf("%d%d",&a[i],&b[i]);
 scanf("%d",&m);
 for (i=1;i<=m/2;i++)   
 {
  scanf("%d%d",&c,&d);
  t=0;
  for (j=1;j<=n/2;j++)
  if (d==b[j]) 
  {
   x=j;
   t=1;
  }
  if (t==1) a[x]+=c;         /*减法就是把这里一段程序改一下*/
  else                       /*if (t==1) a[x]-=c*/
  {                          /*else {*/
   a[l]=c;                    /*a[l]=-c; */
   b[l]=d;                    /*b[l]=d;*/
   l+=1;                      /* l+=1}*/
  } 
 }
 for (i=1;i<=l-1;i++)
 for (j=i;j<=l-1;j++)
 if (b[i]<b[j])
 {
  k=b[i];
  b[i]=b[j];
  b[j]=k;
  k=a[i];
  a[i]=a[j];
  a[j]=k;
 }
 for (i=1;i<=l-1;i++)
 printf("%d %d ",a[i],b[i]); 
 return 0; 
}