/*
猜数字
产生随机数
    用户猜测 记录猜测次数
    比较    
        大
        小
        中 判断数、break
    再次猜测

    猜中次数回馈
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int number = rand() %100;

    int x, N;   //x猜测数字 N猜测次数
    scanf("%d %d", &x, &N);
    int i; // i 记录猜测次数
    int judge = 0;  //判断是否猜中

    for ( i = 1; i <= N; i++)
    {
        if (x < number)
        {
            printf("Too small\n");
        }
        else if (x > number)
        {
            printf("Too big\n");
        }
        else
        {
            judge = 1;
            break; 
        }
        scanf("%d", &x);
    }
    
    if (judge == 1)
    {
        if (i == 1)
        {
            printf("Bingo!\n");
        }
        else if (i <= 3)
        {
            printf("Lucky you!\n");
        }
        else if (i <= N)
        {
            printf("Good Guess!\n");
        }
    }
    else
    {
        printf ("game over!\n");
    }
    
    

    return 0;
}


// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h> 
// #include <stdlib.h>
// #include <time.h>

// int main(void)
// {
// 	srand(time(0));
// 	int number = rand() % 100;
// 	int x,N;
// 	scanf("%d %d",&x,&N);
// 	int count = 1;

// 	while (x != number){
// 		if (x >= 0) {

// 			if (x > number) {
// 				printf("Too Big\n");
// 			}
// 			else if (x < number) {
// 				printf("Too Small\n");
// 			}

// 		}

// 		else {
// 			printf("Game Over\n");
// 			break;
// 		}

// 		scanf("%d", &x);
// 		count++;

// 		if (count > N) {
// 			printf("Game Over\n");
// 			break;
// 		}


// 	} 

// 	if (x >= 0) {
// 		if (count == 1) {
// 			printf("Bingo!\n");
// 		}
// 		else if (count > 1 && count <= 3) {
// 			printf("Lucky You!\n");
// 		}
// 		else if (count > 3 && count <= N) {
// 			printf("Good Guess!\n");
// 		}
// 	}
	

// 	system("pause");
// 	return 0;
// }
