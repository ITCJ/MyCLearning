/*
������������

��д����һ��Ӣ����ָ�����ַ����滻Ϊ��һ�ַ����������ע�⣺����ָ���ַ���ʱ����Сд�޹أ������п��ܶ�γ��֡�

��������ʽ��

�ȴӱ�׼�����з�����������Ӣ���ַ�����ÿ���ַ�����Ϊ�գ����Ȳ�����20�����ַ����в�����ֿո񣩣��ֱ��ʾ���滻���ַ������滻�ɵ��ַ�����Ȼ������һ������һ��Ӣ�ģ����Ȳ�����200������ĩ�лس����С�

�������ʽ��

�������Ӣ�İ�ָ���ַ����滻���������׼����ϣ�ĩβӦ��һ���س����С�

���������롿

th
Hello
This second edition of "The C Programming Language" describes C as defined by the ANSI standard. Modern compilers already support most features of the standard.

�����������

Hellois second edition of "Helloe C Programming Language" describes C as defined by Helloe ANSI standard. Modern compilers already support most features of Helloe standard.

������˵����

����������ı��滻���ַ���Ϊth�������Ǵ�Сд�޹ز����滻��������һ��Ӣ����Ϣ�����ĸ��Ӵ�Ҫ�滻��Th��Th��th��th���ֱ��滻ΪHello��������Ϣԭ�������

�����ֱ�׼������Ҫ����ʵ��ָ���ַ����Ĵ�Сд�޹ز����滻���ύ�����ļ���Ϊexam2.c��exam2.cpp��
*/

/*
    //�� ��һ��Ҫ�����������ֻҪ�������
    ��ȡ ���ҡ��滻���ı� ����
    �����½��в���ƥ�䣬��ƥ�䣬����滻�ı�
        ����ƥ�䣬�����ʱֹͣ��������м���
            ��ȫ����ȣ�����滻����ԭ�е�index+���� 
*/

#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    char chaZhao[21] = { 0 };
    char tiHuan[21] = {0};
    char wenBen[201] = {0};
    int lenth;
    gets(chaZhao);
    gets(tiHuan);
    gets(wenBen);
    lenth = strlen(chaZhao);

    for (int i = 0; wenBen[i] != 0; i++)
    {
        int j = 0;
        int piPei = 0;
        if (wenBen[i] == chaZhao[j] || wenBen[i] == chaZhao[j]+32 || wenBen[i] +32 == chaZhao[j] || wenBen[i]+32 == chaZhao[j]+32)
        {
            while (wenBen[i + piPei] == chaZhao[j + piPei] ||
                    abs(wenBen[i + piPei] - chaZhao[j + piPei]) == 32
                    &&  wenBen[i + piPei] != 0
                    &&  chaZhao[j + piPei] != 0)
                piPei++;
        }
        

        if (piPei == lenth)
            printf("%s", tiHuan);

        i += piPei;
        
        printf("%c", wenBen[i]);
    }
    
    return 0;
}




// ����
#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    char a[20] = {0};
    char b[20] = {0};
    char c[200] = {0};

    int z;
    for (z = 0;; z++)
    {
        *(a + z) = getchar();
        if (*(a + z) == 10)
        {
            break;
        }
    }

    int x;
    for (x = 0;; x++)
    {
        *(b + x) = getchar();
        if (*(b + x) == 10)
        {

            break;
        }
    }

    int v;
    for (v = 0;; v++)
    {
        *(c + v) = getchar();
        if (*(c + v) == 10)
        {

            break;
        }
    }

    int rem = 0;
    int i, j, q, k;//ѭ������
    i = 0;
    int index;
    int p = 0;//���
    int first = 0;//��0��Ԫ�ؿ�ʼPrint
    for (j = 0; j < strlen(c) - 1; j++)
    {
        if (a[0] == c[j] || (a[0] - c[j] == 32))
        {
            index = j;//����a�������ַ�ʱc�ַ��±�
            int n = j;

            for (k = 0; k < strlen(a) - 1; k++, n++)
            {
                if (a[k] != c[n] && (a[k] - c[n] != 32))
                {
                    p = 1;
                }
            }
        }
        else
        {
            continue;
        }
        if (p == 0)
        {
            for (q = first; q < index; q++)
            {
                printf("%c", c[q]);//����滻�ַ�ǰԭ�ַ���
            }
            for (q = 0; q < strlen(b) - 1; q++)
            {
                printf("%c", b[q]);//����滻�ַ���
            }
            first = index + strlen(a) - 1;
            rem = index;
        }

        p = 0;
    }
    for (i = rem + strlen(a) - 1; i < strlen(c) - 1; i++)
    {
        printf("%c", c[i]);
    }

    return 0;
}
