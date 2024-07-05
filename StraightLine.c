#include<stdio.h>
#include<math.h>
int main()
{
	int n, i;
	float X[50], Y[50], x=0, y=0, xy=0, x2=0, a, b;
	printf("Enter The Number of Values: ");
	scanf("%d", &n);
	printf("Enter The Value of X & Y:\n");
	for(i=0; i<n; i++)
	{
		scanf("%f", &X[i]);
		scanf("%f", &Y[i]);
		x += X[i];
		y += Y[i];
		xy += (X[i]*Y[i]);
		x2 += (X[i]*X[i]);
	}
	b = ((n*xy - x*y) / (n*x2 - x*x));
	a = ((y - b*x) / n);
	printf("The Equation is: y = %0.2f + %0.2fx\n", a,b);
}

/*
0 1.1
1 1.9
2 2.7
3 3.5
4 4.3
*/
