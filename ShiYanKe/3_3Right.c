#include<stdio.h>
int main()
{
	int i,n,m,q,a[10000],j;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++)
		a[i]=i;
	for(i=1;i<=n-1;i++)
	{	
		q=q+m-1;
		if(q>=n-i+2&&q<2*(n-i+2)-1)
			q=q-(n-i+1);
		else if(q>=2*(n-i+2)-1)
		{
			int k=(q-1)/(n-i+1);
			q=q-k*(n-i+1);
		}
		for(j=q;j<=n-i+1;j++)
			a[j]=a[j+1];//将退出的猴子覆盖，后面的依次前移一位
		if(q==n-i+1)
			q=1;
	}
	printf("%d",a[1]);
	return 0;
}