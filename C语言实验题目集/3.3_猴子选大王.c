/*
������������Ҫ��nֻ������ѡ��һλ���������Ǿ���ʹ������ķ�����
nֻ����Χ��һȦ����1��n˳���š��ӵ�qֻ���ӿ�ʼ����1��m������������m�ĺ����˳���ѡ����һ���ִ��˳�����ֻ���ӵ���һֻ��ʼ��1��m������ֱ��ʣ�µ����һֻΪ���������������ֻ���ӱ�ѡΪ������
��������ʽ������̨������������n��m��q��
�������ʽ��������ѡΪ�����ĺ��ӱ�š�
���������롿
7  4  3
�����������
4
������˵������������n �� 7��m �� 4��n �� 3�����4
�����ֱ�׼������Ҫ��������ѡΪ�����ĺ��ӱ�ţ���ȫ��ȷ��20�֣�ÿ�����Ե�4�֡��ϴ�C�����ļ���Ϊmonkey.c��
*/

/*
	nֻ���ӣ���m�Σ���q��ʼ
	
	ֵΪ1��nά���飬��0�Ӻ�Ϊm������mʱ��0
	����һ��Ϊnʱ����0��ʼ
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	int* monkey;
	monkey = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		monkey[i] = 1;
	}

	int left = n;
	int mCount = 0;
	int index = q-1;
	while (left != 1) //һ��ֻǰ��һ�����ӣ���Ҫ������ѭ��һ��m����ԭ�����Լ��ĳ��򣬸����״�
	{
		mCount += monkey[index];
		if (mCount == m)
		{
			mCount = 0;
			monkey[index] = 0;
		}
		
		if (index + 1 == n)
		{
			index = 0;
		}
		else
		{
			index++;
		}

		left = 0;
		for (int i = 0; i < n; i++)
		{
			left += monkey[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (monkey[i] == 1)
		{
			printf("%d", i + 1);
		}
	}

	return 0;
}

//���Ѵ�
#include <stdio.h>

int main()
{
	int i, n, m, q, a[10000], j;
	scanf("%d %d %d", &n, &m, &q);
	for (i = 1; i <= n; i++)
		a[i] = i;

	for (i = 1; i <= n - 1; i++)
	{
		q = q + m - 1;
		if (q >= n - i + 2 && q < 2 * (n - i + 2) - 1)
			q = q - (n - i + 1);
		else if (q >= 2 * (n - i + 2) - 1)
		{
			int k = (q - 1) / (n - i + 1);
			q = q - k * (n - i + 1);
		}
		
		for (j = q; j <= n - i + 1; j++)
			a[j] = a[j + 1];//���˳��ĺ��Ӹ��ǣ����������ǰ��һλ
		if (q == n - i + 1)
			q = 1;
	}

	printf("%d", a[1]);

	return 0;
}