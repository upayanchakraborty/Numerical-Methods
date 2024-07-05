#include<stdio.h>
#include<math.h>
float f(float x)
{
	return ((x*sin(x)) + pow(x,3));
}
int main()
{
	int n, i;
	float a, b, h, x[100], y[100], sum=0, sum1=0, in;
	printf("Enter The Lower & Upper Limit: ");
	scanf("%f%f", &a, &b);
	printf("Enter The Number of Intervals: ");
	scanf("%d", &n);
	h = (b - a) / n;
	for(i=0; i<=n; i++)
	{
		x[i] = a + (i*h);
		y[i] = f(x[i]);
	}
	for(i=1; i<n; i+=2)
	{
		sum = sum + y[i];
	}
	for(i=2; i<n; i+=2)
	{
		sum1 = sum1 + y[i];
	}
	in = (h/3) * ((y[0] + y[n]) + 4*sum + 2*sum1);
	printf("\nThe Integration is %0.3f", in);
}
