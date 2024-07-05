#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() 
{
    float **a, **A, *x, s, max;
    int i, j, n, k, flag = 0, pos, cnt, f = 0;

    printf("Enter the number of equations:");
    scanf("%d", &n);

    printf("Enter augumented matrix for the system of equations:\n");

    a = (float*)malloc(n * sizeof(float));
    for(i = 0; i < n; i++)
        a[i] = (float*)malloc((n + 1) * sizeof(float));

    A = (float **)malloc(n * sizeof(float *));
    for (i = 0; i < n; i++)
        A[i] = (float *)malloc((n + 1) * sizeof(float));

    x = (float*)malloc(n * sizeof(float));

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n+1; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }

    for(i = 0; i < n; i++)
    {
        max = fabs(a[i][0]);
        for(j = 0; j < n; j++)
        {
            if(fabs(a[i][j]) >= max)
            {
                max = fabs(a[i][j]);
                pos = j;
            }
        }
        s = 0.0;
        for(j = 0; j < n; j++)
        {
            if(j != pos)
                s = s + fabs(a[i][j]);
        }
        if(fabs(a[i][j] > s))
        {
            flag = 1;
            for(j = 0; j < n+1; j++)
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
        printf("The system of equations is diagonally dominant\n");
        printf("The augmented matrix after rearrangement:\n");
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n+1; j++)
            {
                printf("%0.3f ", A[i][j]);
            }
            printf("\n");
        }
        printf("Enter no. of iterations:");
        scanf("%d", &cnt);
        k = 0;
        while(k < cnt)
        {
            for(i = 0; i < n; i++)
            {
                x[i] = A[i][n];
                for(j = 0; j < n; j++)
                {
                if(i != j)
                    x[i] = x[i] - A[i][j] * x[j];
                }
                x[i] = x[i] / A[i][i];
            }
            k++;
        }
        printf("Solutions:\n");
        for(i = 0; i < n; i++)
            printf("x%d = %0.3f\n", i+1, x[i]);
    }
    else
    {
        printf("System of equations is not diagonally dominant\n");
        printf("Guass-Seidel method can not be applicable");
    }
    return 0;
}
/*
-2 3 10 22
1 10 -1 22
10 2 1 9
*/
