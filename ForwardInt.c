#include<stdio.h>
#include<math.h>
float x[100], y[100][100], res=0;
void for_int(int n, float h, float a)
{
	int i, j;
	float u, p=1, func=y[0][0];
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
	u = (a - x[0]) / h;
	for(j=1; j<n; j++)
	{
		p = p * (u - j + 1) / j;
		func += p * y[1][j];
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
		for_int(n, h, val);
	}
	printf("The Result is %0.3f", res);
	return 0;
}

/*
30 0.5000
35 0.5736
40 0.6428
45 0.7071
50 0.7660
55 0.8192
*/
