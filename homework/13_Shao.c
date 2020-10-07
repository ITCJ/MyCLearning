#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void max(int student[][7],int a[],int b);
int main()
{
	int i,j;
	int s[3][7],aa[2];
	srand((unsigned)time(NULL));
	for(i=0;i<3;i++)
	{
		printf("请输入第%d个学生的学号：",i+1);
		scanf("%d",&s[i][0]);
		printf("\n英语\t高数\t计算机\t专业1\t专业2\t专业3\n");
		for(j=1;j<7;j++)
		{
	      do
		{
			s[i][j]=1+rand()%100;
		}
		while(s[i][j]<50);
		printf("%d\t",s[i][j]);
		}
		printf("\n");
	}
	
	for(i=1;i<7;i++)
	{
		max(s,aa,i);
		printf("\n第%d门课程最高者学号为:%d,分数为：%d\n",i,aa[0],aa[1]);
	}
	return 0;
}
void max(int student[][7],int a[],int b)
{
	int i;
	a[1]=0;
	for(i=0;i<3;i++)
	{
		if(a[1]<student[i][b])
		{
			a[0]=student[i][0];
			a[1]=student[i][b];
		}
	}
	

}