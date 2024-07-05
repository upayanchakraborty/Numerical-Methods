#include<stdio.h>
#include<math.h>
double F(double x)
{
	return(pow(x,3)-(3*x)-5);
}
int main()
{
	float a, b, x, e;
	int n=0;
	do
	{
		printf("Enter The Start & End Point of Range: ");
		scanf("%f%f", &a, &b);
		printf("Enter upto which Decimal Point to Approx: ");
		scanf("%f", &e);
		if((F(a)*F(b))>0.0){
			printf("Error! Try Different Range");
		}
	}while((F(a)*F(b))>0.0);
	printf("Calculation Table:\n\n");
	printf("n\ta\t\tb\t\tx\t\tf(a)\t\tf(b)\t\tf(x)\t\t\n");
	do
	{
	x = (a+b)/2;
	printf("%d\t%f\t%f\t%f\t%f\t%f\t%f\t\n", n++, a, b, x, F(a), F(b), F(x));
	if((F(a)*F(x))<0.0)
		b = x;
	else
		a = x;
	}while(fabs(F(x)) > e);
	printf("The Root is %.3f", x);
	return 0;
}
