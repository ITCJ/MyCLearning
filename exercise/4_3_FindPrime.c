#include <stdio.h>
/*
M,N范围逐个验证

计数
加和输出
*/

int main () 
{
//检验素数方法不好
    // int a, b;
    // int count = 0;
    // int sum = 0;
    // int i = 2;
    // scanf("%d %d", &a, &b);
    // int judge1;
    // float judge2;

    // for ( ; a <= b; a++)
    // {
    //     while ( i < a)
    //     {
    //         judge1 = a/i;
    //         judge2 = 1.0*a/i;
    //         i++;
    //         if (judge1 == judge2)
    //         {
    //             printf("a/i=%d,1.0*a/i=%f", a/i, 1.0*a/i);
    //             count ++;
    //             sum += a;
    //             break;
    //         }
            
    //     }
        
        
    // }
    // printf("%d %d", count, sum);
	
    int M, N;
	scanf("%d %d", &M, &N);
	int i;
	int count = 0;
	int sum = 0;
    if (M == 1)
    {
        M =2;
    }
    
	for (i = M; i <= N; i++) {
		int j;
		int isPrime = 1;
		for (j = 2; j < i; j++) {
			if (i%j == 0) {
				isPrime = 0;
				break;
			}
		}
		if (isPrime) {
			count++;
			sum += i;
		}
	}
	printf("%d %d\n", count, sum);

    return 0;
}