/*
【问题描述】要从n只猴子中选出一位大王。它们决定使用下面的方法：
n只猴子围成一圈，从1到n顺序编号。从第q只猴子开始，从1到m报数，凡报到m的猴子退出竞选，下一次又从退出的那只猴子的下一只开始从1到m报数，直至剩下的最后一只为大王。请问最后哪只猴子被选为大王。
【输入形式】控制台输入三个整数n，m，q。
【输出形式】输出最后选为大王的猴子编号。
【样例输入】
7  4  3
【样例输出】
4
【样例说明】输入整数n ＝ 7，m ＝ 4，n ＝ 3，输出4
【评分标准】本题要求输出最后被选为大王的猴子编号，完全正确得20分，每个测试点4分。上传C语言文件名为monkey.c。
*/

/*
	n只猴子，数m次，从q开始
	
	值为1的n维数组，从0加和为m，等于m时置0
	当下一个为n时，从0开始
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
	while (left != 1) //一次只前进一个猴子，不要在里面循环一个m，见原来我自己的程序，复杂易错
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

//网友答案
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
			a[j] = a[j + 1];//将退出的猴子覆盖，后面的依次前移一位
		if (q == n - i + 1)
			q = 1;
	}

	printf("%d", a[1]);

	return 0;
}