#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	float **a, **A, *x, s, max;
	int i, j, n, k, flag=0, pos, cnt, f=0;
	printf("Enter The Number of Equations: ");
	scanf("%d", &n);
    printf("Enter Augumented Matrix for The System of Equations:\n");
	a = (float**)malloc(n * sizeof(float*));
	for(i=0; i<n; i++)
		a[i] = (float*)malloc((n+1) * sizeof(float));
	A = (float**)malloc(n * sizeof(float*));
	for(i=0; i<n; i++)
		A[i] = (float*)malloc((n+1)*sizeof(float));
	x = (float*)malloc(n*sizeof(float));
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%f", &a[i][j]);
	for(i=0; i<n; i++)
		x[i] = 0.0;
	/*Checking The Dominance*/
	for(i=0; i<n; i++)
	{
		max = fabs(a[i][0]);
		for(j=0; j<n; j++)
		{
			if(fabs(a[i][j]) >= max);
			{
				max = fabs(a[i][j]);
				pos = j;
			}
		}
		s = 0.0;
		for(j=0; j<n; j++)
		{
			if(j != pos)
				s = s + fabs(a[i][j]);
		}
		if(fabs(a[i][pos] > s))
		{
			flag = 1;
			for(j=0; j<n+1; j++)
				A[pos][j] = a[i][j];
		}
		else
		{
			f = 0;
			break;
		}
	}
	if(flag == 1)
	{
		printf("The System of Equation is Diagonally Dominant\n");
		printf("The Augmented Matrix after Rearrangement: \n");
		for(i=0; i<n; i++)
		{
			for(j=0; j<n+1; j++)
				printf("%7.3f", A[i][j]);
			printf("\n");
		}
		printf("Enter No. of Iterations: ");
		scanf("%d", &cnt);
		k = 0;
		while(k < cnt)
		{
			for(i=0; i<n; i++)
			{
				x[i] = A[i][n];
				for(j=0; j<n; j++)
				{
					if(i != j)
						x[i] = x[i] - A[i][j] * x[j];
				}
				x[i] = x[i] / A[i][i];
			}
			k++;
		}
		printf("The Solutions:\n");
		for(i=0; i<n; i++)
			printf("X%d = 0.3f\n", i+1, x[i]);
	}
	else
	{
		printf("The System of Equation is not Diagonally Dominant\n");
		printf("Gauss-Seidal Method can not be Applicable");
	}
	for (i = 0; i < n; i++) {
        free(a[i]);
        free(A[i]);
    }
    free(a);
    free(A);
    free(x);

	return 0;
}

/*
-2 3 10 22
1 10 -1 -22
10 2 1 9
*/

/*
9 -2 1 50
1 5 -3 18
-2 2 7 19
*/
