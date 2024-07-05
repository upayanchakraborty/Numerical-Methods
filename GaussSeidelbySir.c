#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float **a, **A, *x, s, max;
    int i, j, n, k, flag = 0, pos, cnt, f = 0;

    printf("Enter the number of equations:");
    scanf("%d", &n);

    printf("Enter augmented matrix for the system of equations:\n");

    a = (float**)malloc(n * sizeof(float*));
    for (i = 0; i < n; i++)
        a[i] = (float*)malloc((n + 1) * sizeof(float));

    A = (float**)malloc(n * sizeof(float*));
    for (i = 0; i < n; i++)
        A[i] = (float*)malloc((n + 1) * sizeof(float));

    x = (float*)malloc(n * sizeof(float));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            scanf("%f", &a[i][j]);
        }
    }
    for (i = 0; i < n; i++){
        x[i]=0.0;
    }

    for (i = 0; i < n; i++) {
        max = fabs(a[i][0]);
        for (j = 0; j < n; j++) {
            if (fabs(a[i][j]) >= max) {
                max = fabs(a[i][j]);
                pos = j;
            }
        }
        s = 0.0;
        for (j = 0; j < n; j++) {
            if (j != pos)
                s = s + fabs(a[i][j]);
        }
        if (fabs(a[i][pos]) > s) {
            flag = 1;

            for (j = 0; j < n + 1; j++)
                A[i][j] = a[i][j];
        }
        else {
            flag = 0;
            break;
        }
    }

    if (flag == 1) {
        printf("The system of equations is diagonally dominant\n");
        printf("The augmented matrix after rearrangement:\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n + 1; j++)
                printf("%.3f ", A[i][j]);
            printf("\n");
        }
        printf("Enter number of iterations: ");
        scanf("%d", &cnt);

        for (i = 0; i < n; i++)
            x[i] = 0;

        for (k = 0; k < cnt; k++) {
            for (i = 0; i < n; i++) {

                x[i] = A[i][n];
                for (j = 0; j < n; j++) {
                    if (i != j) {

                        x[i] -= A[i][j] * x[j];
                    }
                }

                x[i] /= A[i][i];
            }
        }

        printf("\nSolutions:\n");
        for (i = 0; i < n; i++)
            printf("x%d=%.3f\n", i + 1, x[i]);
    }
    else {
        printf("\nSystem of linear equations is not diagonally dominant");
        printf("\nGauss-Seidel method cannot be applied");
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
Enter the number of equations:3
Enter augmented matrix for the system of equations:
9 -2 1 50
1 5 -3 18
-2 2 7 19
The system of equations is diagonally dominant
The augmented matrix after rearrangement:
9.000 -2.000 1.000 50.000
1.000 5.000 -3.000 18.000
-2.000 2.000 7.000 19.000
Enter number of iterations: 10

Solutions:
x1=6.154
x2=4.313
x3=3.240
*/