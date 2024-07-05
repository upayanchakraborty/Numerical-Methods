#include<stdio.h>
int main()
{
	int i, j, k, n;
	float m[20][20], c, v[10], sum=0.0, det=1.0;
	printf("Enter The Order of Matrix: ");
	scanf("%d", &n);
	printf("Enter The Elements of Augmented Matrix:\n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=(n+1); j++)
		{
			scanf("%f", &m[i][j]);
		}
	}
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			if(i > j)
			{
				c = m[i][j] / m[j][j];
				for(k=1; k<=n+1; k++)
					m[i][k] = m[i][k] - (c * m[j][k]);
			}
		}
	}
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			if(i == j)
				det *= m[i][i];
		}
	}
	if(det == 0)
		printf("Solution Doesn't Exists!");
	else
	{
		v[n] = m[n][n+1] / m[n][n];
		for(i=n-1; i>=1; i--)
		{
			sum = 0;
			for(j=i+1; j<=n; j++)
				sum += m[i][j] * v[j];
			v[i] = (m[i][n+1] - sum) / m[i][i];
		}
		printf("The Solution is:\n");
		for(i=1; i<=n; i++)
			printf("X%d = %0.2f\n", i, v[i]);
	}
	return 0;
}

/*
3 4 5 18
2 -1 8 13
5 -2 7 20
*/
