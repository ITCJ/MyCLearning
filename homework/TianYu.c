#include<stdio.h> 
#include<string.h> 
int main()
{	
	int i,j,capital,lower,figure,space,other;
	char t[3][100];
	capital=lower=figure=space=other=0;
	for(i=0;i<3;i++)
	{		
		printf("请输入第%d行:\n",i+1);
		gets(t[i]); 
		for(j=0;j<100 &&t[i][j]!='\0';j++)
		{			
			if(t[i][j]>='A' && t[i][j]<='Z')
			    capital++;
			else if(t[i][j]>='a' && t[i][j]<='z')
			    lower++;
			else if(t[i][j]>='0' && t[i][j]<='9')
			    figure++;
			else if(t[i][j]=' ')
			    space++;
			else
			    other++;
		}
	}
	printf("英文大写个数为: %d\n",capital);
	printf("英文小写个数为: %d\n",lower);
	printf("数字字符个数为: %d\n",figure);
	printf("空格字符个数为: %d\n",space);
	printf("其他字符个数为: %d\n",other);
	puts (strupr(t));
	
    return 0;
}