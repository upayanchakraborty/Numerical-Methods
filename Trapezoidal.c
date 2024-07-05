#include<stdio.h>
#include<math.h>
float f(float x)
{
	return ((x*sin(x)) + pow(x,3));
}
int main()
{
	int n, i;
	float a, b, h, x[100], y[100], sum=0, in;
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
	for(i=1; i<n; i++)
	{
		sum = sum + y[i];
	}
	in = (h/2) * ((y[0] + y[n]) + 2*sum);
	printf("\nThe Integration is %0.3f", in);
}
