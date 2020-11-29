#include<stdio.h>
#include<math.h>

double jiechen(double a);



int main()
{
	double x=0.5236;
	double n=50;
	double result =0;
	int i=0;
	
//	printf("«Î ‰»Îx∫Õn");
//	scanf("%lf %lf",&x,&n);
	
	for(i=1;i<=n;i++){
		result+=pow(-1,i-1)*pow(x,2*i-1)/jiechen(2*i-1);
	} 
	printf("%.8lf",result);
	return 0;
}

double jiechen(double a)
{
	int b=1;
	int c=1;
	for(b=1;b<=a;b++){
		c*=b;
	}
	return c;
}
	


