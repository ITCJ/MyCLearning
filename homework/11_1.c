/*
随机数 3
三角形-验证形成-计算面积
接收面积-验证正确
*/

#include<stdio.h> 
#include<stdlib.h> 
#include<time.h>
#include<math.h>

int testSquare(int a, int b, int c, float S);
float cacuSquare(int a, int b, int c);

int main()
{	
	int a[3]; // a b c bool s
	float s;
	int i = 0, judge = 0;
	srand((unsigned)time(NULL));

	do 
	{
		for(i=0; i<3; i++)
		{
			//srand((unsigned)time(NULL));
			a[i] = rand()%20 ;
		}
		if( (a[0]+a[1]>a[2] && a[1]+a[2]>a[0] && a[0]+a[2]>a[1]) && a[0] != 0 && a[1] != 0 && a[2] != 0 )
		{
			judge = 1;
		}
	}while(judge != 1);
	
	printf("三边长为:%d %d %d", a[0], a[1], a[2]);
	printf("用户请输入面积：");
	scanf("%f", &s);
		
	if ( testSquare(a[0], a[1], a[2], s) )//不方便调试
	{
		printf("100分");
	}
	else 
	{
		printf("0分");
	}

    return 0;
}


int testSquare(int a, int b, int c, float S)
{
	float system, user;
	int judge = 0;
	
	system = cacuSquare(a,b,c);
	printf("答案是：%.1f\n", system);
	user = S;

	if ( system == user )
	{
		judge = 1;
	}

	return judge;
}

float cacuSquare(int a, int b, int c)
{
	float p = 0;
	float s;

	p = (a + b + c)/2.0;
	s = sqrt( p*(p-a)*(p-b)*(p-c) );
	s = (int)(s*10 + 0.5)/10.0 ;

	return s*1.0;
}