/*
【问题描述】

从标准输入中输入两组整数(每组不超过20个整数，每组整数中的元素不重复，并且整数大于等于0)，编程求两组整数的交集，即在两组整数中都出现的整数，并按从小到大顺序排序输出。若交集为空，则什么都不输出。

【输入形式】

在两行上分别输入两组整数，以一个空格分隔各个整数，以-1作为输入结束。

【输出形式】

按从小到大顺序排序输出两组整数的交集（以一个空格分隔各个整数，最后一个整数后的空格可有可无）。

【样例输入】

5  105  0  4  32  8  7  9  60  -1
5  2  87  10  105  0  32  -1

【样例输出】

0  5  32  105

【样例说明】

第一组整数有9个，分别为5  105  0  4  32  8  7  9  60，第二组整数有7个，分别为5  2  87  10  105  0  32。在这两组整数中都出现的整数有四个，按从小到大顺序排序后输出的结果为0  5  32  105。

【评分标准】该题要求输出两组整数的交集，共有5个测试点，提交程序文件名为and.c。
*/

/*
两组整数
一个与多个比较
    if 符合 存储
    -1 结束
排序待输出结果
    两两比较

注意：20个数不计算-1，所以需要21宽度的数组
*/

//#include <stdio.h>
//
//void readNumber(int order, int data[][21]);
//void compare(int num, int data[][21]);
//void setOrder(int num, int data[][21]);
//
//int main()
//{
//    int data[3][21] = { 0 };
//
//    readNumber(0, data);
//    readNumber(1, data);
//
//    compare(0, data);
//
//    setOrder(2, data);
//
//    int i = 0;
//    while (data[2][i] != -1)
//    {
//        printf("%d ", data[2][i]);
//        i++;
//    }
//
//
//    return 0;
//}
//
//void readNumber(int order, int data[][21])
//{
//    int i = 0;
//    do
//    {
//        scanf("%d", &data[order][i]);
//        i++;
//    } while (data[order][i - 1] != -1);
//
//}
//
//void compare(int num, int data[][21]) //每个数字都比较另一数组所有数字
//{
//    int k = 0;
//    for (int i = 0; i < 21; i++)
//    {
//        for (int j = 0; j < 21; j++)
//        {
//            if (data[num][i] == data[num + 1][j])
//            {
//                data[num + 2][k] = data[num][i];
//                k++;
//                break;
//            }
//        }
//    }
//}
//
////排序
//void setOrder(int num, int data[][21])
//{
//    int width = 21;
//    int cache;
//    for (size_t i = 0; i < width; i++)
//    {
//        for (size_t j = 0; j < width; j++)
//        {
//            if (data[num][j + 1] == -1) //如果后一个是-1，说明结束
//            {
//                break;
//            }
//
//            if (data[num][j] > data[num][j + 1]) //如果大于后一个，交换位置
//            {
//                cache = data[num][j + 1];
//                data[num][j + 1] = data[num][j];
//                data[num][j] = cache;
//            }
//        }
//
//    }
//}