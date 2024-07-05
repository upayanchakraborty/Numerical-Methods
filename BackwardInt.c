#include<stdio.h>
#include<math.h>
float x[100], y[100][100], res=0;
void back_int(int n, float h, float a)
{
	int i, j;
	float u, p=1, func=y[n-1][0];
	for(j=1; j<n; j++)
	{
		for(i=j; i<n; i++)
		{
			y[i][j] = y[i][j-1] - y[i-1][j-1];
		}
	}
	printf("The Table is:\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<=i; j++)
			printf("%0.4f\t", y[i][j]);
		printf("\n");
	}
	u = (a - x[n-1]) / h;
	for(j=1; j<n; j++)
	{
		p = p * (u + j - 1) / j;
		func += p * y[n-1][j];
	}
	res = func;	
}	
int main()
{
	int n, i, flag=0;
	float h, val;
	printf("Enter The Number of Values: ");
	scanf("%d", &n);
	printf("Enter X & Y Values:\n");
	for(i=0; i<n; i++)
	{
		scanf("%f%f", &x[i], &y[i][0]);
	}
	printf("Enter The Interpolation Point: ");
	scanf("%f", &val);
	h = x[1] - x[0];
	for(i=1; i<n-1; i++)
	{
		if((x[i+1] - x[i]) != h)
			break;
		else
			flag=1;
	}
	if(flag == 0)
		printf("Error Due to Wrong Format");
	else
	{
		back_int(n, h, val);
	}
	printf("The Result is %0.3f", res);
	return 0;
}

/*
2 12
4 10
6 9
8 14
*/
