/*水仙花数
153 = 1^3 + 5^3 + 3^3
一个逐渐增大的数字 roll 最大7*7*7+7*7*7+7*7*7 = 1029
取位、加和
    signal = roll%10
    sum = signal^3
    /10
判断、输出
    sum = roll
*/
#include <stdio.h>
#include <math.h>

int main () 
{
    int roll, store;
    int sum;
    int signal = 1;
    int basic;
    int big;
    int small = 1;

    int i;
    scanf("%d", &basic);

    for ( i = 1; i < basic; i++)
    {
        small *= 10;
    }
    big = small *10;
    //printf("%d", small); //检验方法

//遍历
    for ( roll = small; roll < big; roll++)
    {
        store = roll;
        while (store != 0) //do 处理0 while 不好处理0
        {
            signal = store%10;
            sum += pow (signal, basic);
            store /= 10;
        }

        if (sum == roll)
        {
            printf("%d\n", roll);
        }

        sum = 0;
        signal = 1;
    }

// example code 
    // int N;
	// scanf("%d", &N);
	// int i,j,k,h;
	// int product = 1;
	// for (i = 1; i < N; i++) {
	// 	product *= 10;
	// }

	// int p,q,sum;
	// for (j = product; j < product * 10; j++) {
	// 	int x = j;
	// 	sum = 0;
	// 	for (k = 0; k < N; k++) {
	// 		p = x % 10 ;
	// 		x /= 10;
	// 		q = 1;

	// 		for (h = 0; h < N; h++) {
	// 			q *= p;	
	// 		}

	// 		sum += q;
	// 	}

	// 	if (j == sum) {
	// 		printf("%d\n", j);
	// 	}
	// }
    
    return 0;
}