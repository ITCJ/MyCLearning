/*
������������
��дһ�����򣬶�������ַ���s��t��������Ĺ������ַ�����
 ��������ʽ��
����Ļ���ж��봮s��t��s��t�������ַ����ɣ����ȶ�����50���ַ�����������ȷ��ֻ��Ψһ��������Ӵ������û�й����Ӵ�����ӡNo Answer

�������ʽ��
�ڵ������������s�ʹ�t��������Ӵ����ڽ�β���һ���س�����

�㷨��ʾ����һ��int�͵ļ�������¼��ǰƥ�䳤�ȣ���һ���ַ������¼��ǰƥ���Ӵ���������ڸ����Ӵ����������Ӧ�滻��
������˵����
 �������Ļ�����������ݣ�
aabcdababce
12abcabcdace
���������Ϊ��
abcda
�����ֱ�׼��
�����ȫ��ȷ��20�֣�ÿ�����Ե�4�֣��ύ�����ļ���Ϊc0505.c��
*/

/*
��for a����for b
	��ƥ�䵽һλʱ���ö�������index����ֱ��!=,�õ����Ⱥ�������һ��Ҳ�ɣ�����Ŀ�ʼ��

*/

#include <stdio.h>

int main()
{
	char a[51] = { 0 };
	char b[51] = { 0 };
	int cache[2] = { 0 };

	scanf("%s", &a);
	scanf("%s", &b);

	for (int i = 0; i < 51; i++)
	{
		for (int j = 0; j < 51; j++)
		{
			int length = 1;
			if (a[i] == b[j])
			{
				while (a[i + length] == b[j + length] && a[i + length] != 0 && b[j + length] != 0)
					length++;
			}
			
			if (cache[0] < length)
			{
				cache[0] = length; //cache[0]�泤��
				cache[1] = j;		//cache[1]�濪ʼ��λ��
			}

			if (a[i] == 0 || b[j] == 0) //�ų������Σ��ܲ�����
				break;
		}
			
	}

	for (int i = cache[1]; i <= cache[0] + cache[1]; i++)
		printf("%c", b[i]);

	return 0;
}

//int compare(int index, char a[], char b[], char cache[])
//{
//	int length;
//
//	return length;
//}