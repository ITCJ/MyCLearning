/*
产生随机数
数组存放
小到大排序输出

找出能被3整除
*/

/*
随机
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
	int n, i, j, store;
	int* a;

	scanf("%d", &n);
	a = (int*)malloc(n*sizeof(int));
	srand( (unsigned)time(NULL) );

	for( i = 0; i < n; i++)
	{
		a[i] = rand();
		printf("%12d", a[i]);
		
		if( i%6 == 5) // 列数-1
		{
			printf("\n");
		}
	}

	
	for( i = 0; i < n-1; i++)
	{
		for( j = 0; j<n-1; j++)
		{
			if( a[j] > a[j + 1])
			{
				store = a[j + 1];
				a[j + 1] = a[j];
				a[j] = store;
			}
		}

	}

	printf("\n\n");
	for(i = 0; i<n; i++)
	{
		printf("%12d", a[i]);
		if( i%6 == 5)	printf("\n");
	}

	printf("\n\n");
	for(i=0, j=0; i<n; i++)
	{
		if( a[i] % 3 == 0)
		{
			printf("%12d", a[i]);
			
			if(j%6 == 5)
			{
				printf("\n");
			
			}
			j++;
		}
	}

	free(a);
	
    return 0;
}