/*
二进制	10进制
0.1		0.5
0.01	0.25
0.001	0.125
0.0001	0.0625

*/


#include <stdio.h>

int main()
{
	int M, N;
	int i = 1;
	int multi = 1;
	int store = 0;
	int storeM = 0;
	int storeM2 = 0;
	int k = 1;
	int j;

	start:
	scanf("%d %d", &M, &N);
	storeM = storeM2 = M;


	if (M < 10 && N < 10)
	{
		for	(j = 0; j < storeM2; j++)
		{
			for (k = 0; k < M; k++)
			{ 
				for (i = 1; i < storeM; i ++)
				{
					multi *= 10;
				}
				multi *= N;
				store += multi;
				multi = 1;
				storeM --;
			}
			
			M --;
			storeM = M;
		}
	}
	else
	{
		goto start;
	}

    printf("%d", store);

	return 0;
}

