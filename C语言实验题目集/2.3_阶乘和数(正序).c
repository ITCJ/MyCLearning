/*
������������

һ���������������������ĸ�λ���ֵĽ׳�֮�ͣ������������Ϊ�׳˺���������������145��1!+4!+5!����145�����145����һ���׳˺���������һ�����������������ĸ�λ���ֵĽ׳�֮�ͣ����ж����Ƿ���һ���׳˺�����ע�⣺��������������Լ�������ĸ�λ���ֵĽ׳�֮�Ͷ����ᳬ��int���͵ı�ʾ��Χ����������������������λ��Ϊ0��

��������ʽ��

�ӿ���̨����һ����������

�������ʽ��

������������������һ�����š�,�����������λ��ʼ�����ɸ��������ĸ�λ���ֵĽ׳������ʽ��Ȼ������Ⱥš�=���͸�λ���ֽ׳�֮�ͣ��������һ������ַ�����Yes����ʾ���������ǽ׳˺�������������ַ�����No����ʾ�����������ǽ׳˺��������Yes��No������س����з�����������ַ�֮�䶼û�пո�ָ���

����������1��

145

���������1��

145,1!+4!+5!=145
Yes


����������2��

1400

���������2��

1400,1!+4!+0!+0!=27
No

����������3��

4

���������3��

4,4!=24
No

������˵����

����1�������������Ϊ145��������ĸ�λ���ֵĽ׳�֮��Ϊ145������145Ϊ�׳˺���������2�������������Ϊ1400��������ĸ�λ���ֵĽ׳�֮��Ϊ27������1400���ǽ׳˺���������3�������������Ϊ4���������ֻ��һλ���֣���׳�Ϊ24��Ҳ���ǽ׳˺�����

�����ֱ�׼��

����Ҫ���ж�������������Ƿ�Ϊ�׳˺������ύ�����ļ���Ϊfact.c��fact.cpp��
*/

/*
����������
�õ���λ����
    ȡ10��
    ��10
��λ���ֽ׳�
    for 0~������
�жϽ׳˺��Ƿ���ڸ���
    �� Yes����
    ���� No����

����������2��

1400

���������2��

1400,1!+4!+0!+0!=27
No

*/
//#include <stdio.h>
//#include <stdlib.h>
//
//int judgePowReadNumber(int readNumber);
//void catchEveryNum(int everyNum[], int readNumber);
//int fact(int input);
//
//int main()
//{
//    int readNumber;
//    int* everyNum;
//    int factSum = 0;
//
//    scanf("%d", &readNumber);
//
//    int num = judgePowReadNumber(readNumber);
//    everyNum = (int*)malloc(num * sizeof(int)); //��̬����
//
//    catchEveryNum(everyNum, readNumber);
//
//    for (size_t i = 0; i < num; i++)
//    {
//        factSum += fact(everyNum[i]);
//    }
//
//    printf("%d,", readNumber);
//    for (int i = num - 1; i >= 0; i--)
//    {
//        printf("%d!", everyNum[i]);
//        if (i > 0)
//        {
//            printf("+");
//        }
//    }
//    printf("=%d\n", factSum);
//
//    if (factSum == readNumber)
//    {
//        printf("Yes");
//    }
//    else
//    {
//        printf("No");
//    }
//
//
//    free(everyNum);
//    return 0;
//}
//
//int judgePowReadNumber(int readNumber) //�ж������˼�λ��
//{
//    int pow = 0;
//    while (readNumber != 0)
//    {
//        readNumber /= 10;
//        pow++;
//    }
//
//    return pow;
//}
//
//void catchEveryNum(int everyNum[], int readNumber)  //��ÿλ���ּ�¼�£���ʵ���Ժ���һ�������ϲ�
//{
//    int i = 0;
//    while (readNumber != 0)
//    {
//        everyNum[i] = readNumber % 10;
//        readNumber /= 10;
//
//        i++;
//    }
//
//}
//
//int fact(int input) //��׳�
//{
//    int result = 1;
//    while (input != 0)
//    {
//        result *= input; //�Ӵ�С�ˣ�ֱ��0
//        input--;
//    }
//
//    return result;
//}