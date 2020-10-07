#include <stdio.h>
#include <stdlib.h>


int main ()
{
	int student = 1;
	char* const obj[] = {"英语", "高数", "计算机", "专业1", "专业2", "专业3"};//字符串常量
	int mode = 1;
	int **data = NULL;
	int i, j, n, judge, store;




	while( mode != 0)
	{
		printf("=========================================\n");
		printf("=                                       =\n");
		printf("=  1. 输入成绩  2.查看排名  0. 退出     =\n");
		printf("=                                       =\n");
		printf("=========================================\n");
		scanf("%d", &mode);
		
		switch (mode)
		{
			case 1:
			{
				printf("输入学生数量:");
				scanf("%d", &n);
				data = (int**)malloc(n * sizeof(int));
				for(i = 0; i < n; i++)
				{
					data[i] = (int*)malloc(8*sizeof(int));	//***
				}
				do
				{
					do
					{
						printf("\n输入学号(输入-1完成):");
						scanf("%d", &student);
						student --;
						if(student < n && student >= 0)
						{
							judge = 1;
						}
						else if (student >= n)
						{
							printf("沙雕，没定义那么多人\n");
							judge = 0;
						}
						else if (student < 0)
						{
							judge = -1;
							break;
						}

					}while(judge != 1);

					for(i = 1; judge > 0&& i<7; i++)
					{
						data[student][0] = student + 1;
						printf("输入%s成绩:",obj[i-1]);
						do
						{	
							j = 1;
							scanf("%d", &data[student][i]);
							if(data[student][i] > 100) 
							{
								printf("你他娘的可真是个天才！再输一遍：\n");
								j = 0;
							}
						} while(j != 1);
						//printf("%d\n",data[student][i]);
					}
				}while( student >= 0);
				
				break;
			}

			case 2:
			{
				for(i = 0; i<n; i++)
				{
					data[i][6] = 0.2*data[i][0] + 0.15*data[i][1] + 0.15*data[i][2]
								+ 0.65*data[i][3] + 0.65*data[i][4] + 0.2*data[i][5];
				}
				
				for( i = 0; i < n-1; i++)
				{
					for( j = 0; j<n-1; j++)
					{
						if( data[j][6] > data[j + 1][6])
						{
							store = data[j + 1];
							data[j + 1] = data[j];
							data[j] = store;		//待定
						}
					}
				}
				printf("=============================================================================\n");
				printf("\t学号\t英语\t高数\t计算机\t专业1\t专业2\t专业3\n");
				for(i=0; i<n; i++)
				{
					printf("排名%d",(int)i+1);
					for(j=0; j<7; j++)
					{
						printf("\t%4d",data[i][j]);
					}
					printf("\n");
				}
				printf("=============================================================================\n");
				
				break;
			}
		}

		free(data); 		
	}





	return 0;
}