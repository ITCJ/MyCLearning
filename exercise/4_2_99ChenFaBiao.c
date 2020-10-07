#include <stdio.h>
/*
对角线两数相等
个位    行不变  外循环
十位    相等终止    
*/

int main ()
{
    int ge, shi, control;
    scanf("%d", &control);

    for ( ge = 1; ge <= control; ge++)
    {
        for ( shi = 1; shi <= control; shi++)
        {
            if (shi < ge)  //采数法
            {
                printf("%d*%d=%d  ", shi, ge, shi*ge);
              
                
            }
            else if (shi == ge)
            {
                printf("%d*%d=%d\n", shi, ge, shi*ge);
                break;
            }
            // else if (control < ge)
            // {
            //     goto out;
            // }
        }
    }
    // out:    
    
//example
	// int x;
	// scanf("%d", &x);
	// int i, j;
	// for (i = 1; i <= x; i++) {
	// 	for (j = 1; j <= i; j++) {
	// 		printf("%d*%d=%d\t",i,j,i*j);
    //         if (i*j <10){
    //             printf("   ");
    //         }
    //         else{
    //             printf("  ");
    //         }
	// 	}
	// 	printf("\n");
	// }
    
    return 0;
}