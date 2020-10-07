#include<stdio.h>
#include<string.h>
int main()
{
	char s[3][100] = {0};
	int i,j,C=0,L=0,F=0,space=0,other=0;
	for(i=0;i<3;i++) gets(s[i]);
    
	for(i=0;i<3;i++)
		for(j=0;j<100;j++)
		{
			if(s[i][j]>='A'&&s[i][j]<='Z')
            {
                C++;
                continue;
            }
			else if(s[i][j]>='a'&&s[i][j]<='z')
            {
                L++;
                continue;
            }
			else if(s[i][j]>='0'&&s[i][j]<='9')		
            {
                F++;
                continue;
            }
			else if(s[i][j]==32)					
            {
                space++;
                continue;
            }
		    else if(s[i][j] != 0) 
            {
                other++;
            }
		}
	printf("英文大写个数为：%d\n英文小写个数为：%d\n数字字符个数为：%d\n空格字符个数为：%d\n其他字符个数为：%d\n",C,L,F,space,other);
	puts(strupr(s));
    puts(strupr(s[1]));
    puts(strupr(s[2]));

	return 0;
}