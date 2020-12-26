/*
【问题描述】
编写一个程序，对输入的字符串s和t，求其最长的公共子字符串。
 【输入形式】
从屏幕分行读入串s和t。s和t由任意字符构成，长度都不超50个字符。输入数据确保只有唯一的最长公共子串。如果没有公共子串，打印No Answer

【输出形式】
在单独行上输出串s和串t的最长公共子串，在结尾输出一个回车符。

算法提示：用一个int型的计数器记录当前匹配长度，用一个字符数组记录当前匹配子串，如果存在更长子串，则进行相应替换。
【样例说明】
 假设从屏幕输入以下内容：
aabcdababce
12abcabcdace
则输出内容为：
abcda
【评分标准】
结果完全正确得20分，每个测试点4分，提交程序文件名为c0505.c。
*/

/*
外for a，内for b
	当匹配到一位时，用短生存期index遍历直到!=,得到长度和两个（一个也可）数组的开始点

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
				cache[0] = length; //cache[0]存长度
				cache[1] = j;		//cache[1]存开始的位置
			}

			if (a[i] == 0 || b[j] == 0) //排除了两次，很不优雅
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