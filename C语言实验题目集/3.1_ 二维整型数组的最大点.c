/*
��ά��������ġ����㡱
������������

���ά��������ġ����㡱����ά����ġ����㡱����Ϊ��ĳ�����������е����ֵ�������������е����ֵ��ע�⣺ĳ�л�ĳ���Ͽ����ж�������㡱��

��������ʽ��

�ӿ���̨�����ά���顣

��һ��ֻ���Կո�ָ�������������n��m��n,m<=10����n�����ά�����������m�����ά�����������

Ȼ���ں���n���������ά�����Ԫ�أ�ÿ����m�������ɿո�ָ��������������ά�����ڸ����ϵ�����Ԫ�ء�

�������ʽ��

�����̨�����ά����ġ����㡱�������±ꡢ���±��С�����˳�������ÿ��һ��������������㡱��ֵ���������Ӧ�����������������ж���1��ʼ����������һ���ո�ָ���

���������롿

3  4

8  60  7  100

10  498  12  49

-71  132  4  85

�����������

100 1 4
498 2 2

������˵����

������һ���������еĶ�ά���飬��һ�е����е�Ԫ��100�ǵ�һ�е����Ԫ�أ�ͬʱҲ�ǵ����е����Ԫ�أ����Ը�Ԫ���ǡ����㡱�����100 1 4��ͬ���ڶ��еڶ��е�Ԫ��498Ҳ�ǵڶ��е����Ԫ�أ�ͬʱ�ǵڶ��е����Ԫ�أ��ʸ�Ԫ��Ҳ�ǡ����㡱�����498 2 2��

�����ֱ�׼��

����Ҫ�������ά��������С����㡱������5�����Ե㡣�ϴ�C�����ļ���Ϊexample1b.c��
*/

/*
�����е����ֵ
n�� m��

��������

������
    ��һ�����ж�
        ����� 1
        ����� 1
        �洢 ���� �� ��
��ӡ�洢

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
//            // *(*vector + j*i) = 0; ���Ƕ�ջ����������
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
//void findNumber(int** vector, int n, int m, int* cache) //�����������
//{
//    for (size_t i = 0; i < n; i++)
//    {
//        for (size_t j = 0; j < m; j++)
//        {
//            if (cache[i] < *(*(vector + i) + j)) //�ҳ����������ֵ
//                cache[i] = *(*(vector + i) + j);
//        }
//    }
//
//    for (size_t i = 0; i < m; i++)
//    {
//        for (size_t j = 0; j < n; j++)
//        {
//            if (cache[n + i] < *(*(vector + j) + i)) //�ҳ����������ֵ
//                cache[n + i] = *(*(vector + j) + i);
//        }
//    }
//
//    for (size_t i = 0; i < n; i++)
//    {
//        for (size_t j = 0; j < m; j++)
//        {
//            if (cache[i] == cache[n + j]) //��������� Ҳ�������
//            {
//                printf("%d %d %d\n", cache[i], i + 1, j + 1);
//            }
//
//        }
//    }
//}

//  //���ѷ���
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