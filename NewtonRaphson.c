#include<stdio.h>
#include<math.h>
double F(double x)
{
	return (pow(x,2)+(2*x)-2);
}
double f(double x)
{
	return((2*x)+2);
}
int main()
{
	float x, e, x1, x2, n1, n2;
	int n=0;
	printf("Enter The Approximate Value: ");
	scanf("%f", &x1);
	printf("Enter upto which Decimal Point to Approx: ");
	scanf("%f", &e);
	printf("Calculation Table:\n\n");
	printf("n\tx\t\tf(x)\t\tf'(x)\t\tf(x)/f'(x)\tx1\t\t\n");
	do
	{
		x2 = F(x1)/f(x1);
		x = x1 - x2;
		printf("%d\t%f\t%f\t%f\t%f\t%f\t\n", n++, x1, F(x1), f(x1), x2, x);
		n1 = x;
		n2 = x1;
		x1 = x;
	}while(fabs(n1-n2) > e);
	printf("The Root is %.3f", x);
	return 0;
}
