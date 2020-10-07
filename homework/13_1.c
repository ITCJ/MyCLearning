/*
主函数
	编号 成绩 英语 高数 计算机基础 专业1 专业2 专业3
	输出
查找某科高分函数	
	[][]    []    int列
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void maxScore( float data[][7], float resu[], int lie );

int main ()
{
	float data[5][7];
	float resu[2] = {0};
	int lie;
	int i, j;
	srand((unsigned)time(NULL));
	
	for(j = 0; j<5; j++)
	{
		printf("请输入学号：");
		scanf("%f", &data[j][0] );

		for(i=1; i<=6; i++)
		{
			data[j][i] = rand()%100;
			printf("\t%5.2f", data[j][i] );
		}
		
		printf("\n");
	}	

		do
		{
			printf("\n输入你要查找最高分的科目(1~6)：");
			scanf("%d", &lie);
			if (lie < 0)
			{
				break;
			}
			maxScore(data, resu, lie);
			
			printf("最高分学生是：%4.f，分数是%4.2f\n", resu[0], resu[1] );
		}while(lie>=1 && lie<=6 );
		
	
	return 0;
}

void maxScore( float data[][7], float resu[], int lie )
{
	int j;
	resu[1] = 0; //重要

	for(j=0; j<5; j++)
	{
		if( resu[1] < data[j][lie] )
		{
			resu[0] = data[j][0];
			resu[1] = data[j][lie];
		}	
	}

}