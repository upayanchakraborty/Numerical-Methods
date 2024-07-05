#include<stdio.h>
int main()
{
    int n, i, j;
    float x[100], y[100], val, sum=0, term;
    printf("Enter The Number of Values: ");
    scanf("%d",&n);
    printf("Enter X & Y Values:\n");
	for(i=0; i<n; i++)
	{
		scanf("%f%f", &x[i], &y[i]);
	}
	printf("Enter The Interpolation Point: ");
	scanf("%f", &val);
    for(i=0; i<n; i++){
        term=1;
        for(j=0; j<n; j++){   
            if(i != j)
               term *= ((val - x[j]) / (x[i] - x[j]));
        }
        sum += term * y[i];    
    }
    printf("The Result is %0.3f",sum);
    return 0;
}

/*
1 2
2 4
3 8
4 6
7 128
*/
