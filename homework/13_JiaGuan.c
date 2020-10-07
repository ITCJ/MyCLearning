#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int check(int n,int a[][7],int b[]);
int main()
{
 int a[5][7],b[2],i,j;
printf("输入5名学生编号,之后随机分别产生他们的英语,高数,计算机基础,专业,专业2,专业3的成绩.\n");
for(i=0;i<5;i++)
{
   printf("请输入第%d个学生的编号:",i+1);
   scanf("%d",&a[i][0]);
   for(j=1;j<7;j++)
   {
     do
     a[i][j]=rand()*100/32767;
  while(a[i][j]<60);
  printf("%d\t",a[i][j]); 
   }
printf("\n");
}
 printf("这六项科目最高分学生的编号和分数分别为:\n");
 for(i=1;i<7;i++)
 {
  check(i,a,b);
   printf("%d  ",b[0]);
  printf("%d  ",b[1]);
  printf("\n");
 }
 
 return 0;
}

int check(int k,int a[][7],int b[])
{
 int i,m=0,n;
 n=a[0][k];
 for(i=1;a[i][0]!=0;i++)
  if(n<a[i][k])
  {
   m=i;n=a[i][k];
  }
 b[0]=a[m][0];
 b[1]=a[m][k];
return b[0],b[1];
}