

#include <stdio.h>

int main()
{
	int M, N;
	int i = 1;
	int multi = 1;
	int store = 0;
	int k = 1;

	scanf("%d %d", &M, &N);
	if (M < 10 && N < 10)
	{
		for (k = 1; k < M; k++)
		{
			for (i = 1; i < M; i ++)
			{
				multi *= 10;
			}
			multi *= N;
			store += multi;
			multi = 1;

			M--;
		}


	}
	else
	{

	}


	return 0;
}

