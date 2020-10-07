#include<stdio.h>
int main ()
{
	int scholarship=0;
	float major1,major2,math,english,computer;
	printf("请输入高数英语计算机基础专业课1专业课2的成绩（以空格分开）");
	scanf("%f %f %f %f %f",&math,&english,&computer,&major1,&major2);
if(english>95)
{
printf("经查询您的英语成绩可获得奖学金100元");
scholarship+=100;
}
if(math>95||computer>95)
{
if(math>95&&computer<=95) printf("经查询您的高数成绩可获得奖学金100元"); 
if(math<=95&&computer>95) printf("经查询您的计算机基础成绩可获得奖学金100元");
if(math>95&&computer>95) printf("经查询您的高数以及计算机成绩共可获得奖学金100元");
scholarship+=100;
}
if((major1+major2)/2>95)
{ 
if(math>=60&&english>=60&&computer>=60)
{
	printf("经查询您的专业课成绩以及其他科目成绩可获得奖学金200元");
	scholarship+=200;
}
}
printf("%d",scholarship);
return 0;
}