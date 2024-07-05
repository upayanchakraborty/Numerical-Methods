#include<stdio.h>
#include<math.h>
int main()
{
	int n, i;
	float X[50], Y[50], x=0, y=0, xy=0, x2=0, a, A, b;
	printf("Enter The Number of Values: ");
	scanf("%d", &n);
	printf("Enter The Value of X & Y:\n");
	for(i=0; i<n; i++)
	{
		scanf("%f", &X[i]);
		scanf("%f", &Y[i]);
		x += X[i];
		y += log(Y[i]);
		xy += (X[i]*log(Y[i]));
		x2 += (X[i]*X[i]);
	}
	b = ((n*xy - x*y) / (n*x2 - x*x));
	A = ((y - b*x) / n);
	a = exp(A);
	printf("The Equation is: y = %0.3f * e^%0.3fx\n", a,b);
}

/*
2 4
4 11
6 30
8 82
10 223
*/
