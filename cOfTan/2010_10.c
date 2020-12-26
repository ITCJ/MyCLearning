#include <stdio.h>

int main() 
{int a=5,b=-1,c; 
c=adds(a,b); 
printf("%d",c); 
c=adds(a,b); 
printf("%d\n",c); 

return 0;
} 
int adds(int x,int y) 
{static int m=0,n=3; 
n*=++m; 
m=n%x+y++; 
return(m); } 
