/*
二维整型数组的“最大点”
【问题描述】

求二维整型数组的“最大点”。二维数组的“最大点”定义为：某个数是所在行的最大值，并且是所在列的最大值。注意：某行或某列上可能有多个“最大点”。

【输入形式】

从控制台读入二维数组。

第一行只有以空格分隔的两个正整数n和m（n,m<=10），n代表二维数组的行数，m代表二维数组的列数。

然后在后续n行上输入二维数组的元素，每行有m个以若干空格分隔的整数，代表二维数组在该行上的所有元素。

【输出形式】

向控制台输出二维数组的“最大点”，按行下标、列下标从小到大的顺序输出，每行一个，先输出“最大点”数值，再输出对应的行数、列数（行列都从1开始计数），以一个空格分隔。

【样例输入】

3  4

8  60  7  100

10  498  12  49

-71  132  4  85

【样例输出】

100 1 4
498 2 2

【样例说明】

输入了一个三行四列的二维数组，第一行第四列的元素100是第一行的最大元素，同时也是第四列的最大元素，所以该元素是“最大点”，输出100 1 4。同样第二行第二列的元素498也是第二行的最大元素，同时是第二列的最大元素，故该元素也是“最大点”，输出498 2 2。

【评分标准】

该题要求输出二维数组的所有“最大点”，共有5个测试点。上传C语言文件名为example1b.c。
*/

/*
所在行的最大值
n行 m列

输入数组

找最大点
    对一个数判断
        行最大 1
        列最大 1
        存储 本身 行 列
打印存储

*/


//#include <stdio.h>
//#include <stdlib.h>
//
//void readNumber(int** vector, int n, int m);
//void findNumber(int** vector, int n, int m, int* cache);
//
//int main()
//{
//    int n, m;
//    int** vector;
//    int* cache;
//    scanf("%d %d", &n, &m);
//
//    vector = (int**)malloc(sizeof(int*) * n);
//    cache = (int*)malloc(sizeof(int*) * n + m);
//
//    for (size_t i = 0; i < n; i++)
//    {
//        vector[i] = (int*)malloc(sizeof(int) * m);
//    }
//    for (size_t i = 0; i < m + n; i++)
//    {
//        // cache[i] = (int*)malloc(sizeof(int) * 3);
//        cache[i] = 0;
//    }
//
//    for (size_t j = 0; j < n; j++)
//    {
//        for (size_t i = 0; i < m; i++)
//        {
//            *(*(vector + j) + i) = 0;
//            // *(*vector + j*i) = 0; 不是堆栈不能这样用
//        }
//    }
//
//
//    readNumber(vector, n, m);
//    findNumber(vector, n, m, cache);
//
//
//
//    return 0;
//}
//
//void readNumber(int** vector, int n, int m)
//{
//    for (size_t j = 0; j < n; j++)
//    {
//        for (size_t i = 0; i < m; i++)
//        {
//            scanf("%d", *(vector + j) + i);
//        }
//    }
//}
//
//// void readNumber(int **vector, int n, int m)
//// {
//
////     for (size_t i = 0; i < m*n; i++)
////     {
////         scanf("%d", (*vector+i) );
////     }    
//
//// }
//
//void findNumber(int** vector, int n, int m, int* cache) //这个方法不错
//{
//    for (size_t i = 0; i < n; i++)
//    {
//        for (size_t j = 0; j < m; j++)
//        {
//            if (cache[i] < *(*(vector + i) + j)) //找出所有行最大值
//                cache[i] = *(*(vector + i) + j);
//        }
//    }
//
//    for (size_t i = 0; i < m; i++)
//    {
//        for (size_t j = 0; j < n; j++)
//        {
//            if (cache[n + i] < *(*(vector + j) + i)) //找出所有列最大值
//                cache[n + i] = *(*(vector + j) + i);
//        }
//    }
//
//    for (size_t i = 0; i < n; i++)
//    {
//        for (size_t j = 0; j < m; j++)
//        {
//            if (cache[i] == cache[n + j]) //既是最大行 也是最大列
//            {
//                printf("%d %d %d\n", cache[i], i + 1, j + 1);
//            }
//
//        }
//    }
//}

//  //网友方法
//int main()
//{
//	int a[10][10], n, m, i, j, k;
//	scanf("%d%d", &n, &m);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &a[i][j]);
//		}
//	}
//	int row, col, s, flag = 1, col1, s1, t = 0;
//	for (i = 0; i < n; i++)
//	{
//		s = a[i][0];
//		row = i, col = 0;
//		for (j = 1; j < m; j++)
//		{
//			if (a[i][j] > s)
//			{
//				s = a[i][j];
//				col = j;
//			}
//		}
//		for (j = 0; j < m; j++)
//		{
//			if (a[i][j] == s && j != col)
//			{
//				s1 = a[i][j];
//				col1 = j;
//				t = 1;
//			}
//		}
//		for (k = 0; k < n; k++)
//		{
//			if (a[k][col] > s)
//				flag = 0;
//			if (flag == 0)
//				break;
//		}
//		row++, col++;
//		if (flag)
//			printf("%d %d %d\n", s, row, col);
//		flag = 1;
//		if (t)
//		{
//			for (k = 0; k < n; k++)
//			{
//				if (a[k][col1] > s1)
//					flag = 0;
//				if (flag == 0)
//					break;
//			}
//			col1++;
//			if (flag == 1)
//				printf("%d %d %d\n", s1, row, col1);
//			t = 0;
//		}
//	}
//	return 0;
//}