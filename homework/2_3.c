#include <stdio.h>

int main()
{
int x,y;

y=5; x=14; 
y=((x=3*y,x+6),x-1);

printf("x=%d,y=%d",x,y);


return 0;

}