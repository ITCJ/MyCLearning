#include <stdio.h>

int main ()
{
  int x, y;
  int z = 0;
  int a[5];
  int cnt = 0;

  scanf("%d", &x);
  y = x;

  while (y != 0)
  {
    a[cnt] = y%10;
    z = z*10 + y%10; 
    y = y/10;
    cnt ++;
  }
  if (y == 0)    cnt = 1;

  
    return 0;
}