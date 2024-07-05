#include<stdio.h>
#include<math.h>
float low[50], high[50], f[50], xi[50], cf[50];
float freq;
int n;

float Mean()
{
    float sum=0, mean;
    int i;
    for(i=0; i<n; i++)
	{
        xi[i] = (low[i] + high[i]) / 2;
        sum += (f[i] * xi[i]);
        freq += f[i];
    }
    mean = sum/freq;
    return mean;
}

float Median()
{
	float median;
	int i;
	cf[0] = f[0];
	for(i=1; i<n; i++)
	{
		cf[i] = cf[i-1] + f[i];
	}
	for(i=0; cf[i]<=freq/2; i++);
	median = low[i] + ((high[i] - low[i]) * ((freq/2 - cf[i-1]) / f[i]));
	return median;
}

float Mode()
{
	float mode;
	int i, y=f[0], pos;
	for(i=1; i<n; i++)
	{
		if(f[i] > y)
		{
			y = f[i];
			pos = i;
		}
	}
	mode = low[pos] + ((high[pos] - low[pos]) * ((f[pos] - f[pos-1]) / (2*f[pos] - f[pos-1] - f[pos+1])));
	return mode;
}

float SD(float mean)
{
	float s, sd;
	int i;
	for(i=0; i<n; i++)
	{
		s += (xi[i] - mean) * (xi[i] - mean) * f[i];
	}
	sd = sqrt(s/freq);
	return sd;
}

int main()
{
    int i;
	float m, md, mode, s;
    printf("Enter The Number of Intervals: ");
    scanf("%d",&n);
    printf("Enter the Intervals and Frequencies(Low High Freq): \n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&low[i]);
        scanf("%f",&high[i]);
        scanf("%f",&f[i]);
	}
    m=Mean();
    md=Median();
    mode=Mode();
    s=SD(m);
    printf("\nMean : %0.3f\n",m);
    printf("\nMedian : %0.3f\n",md);
    printf("\nMode : %0.3f\n",mode);
    printf("\nSD : %0.3f\n",s);
    return 0;
}

/*
200 220 7
220 240 15
240 260 20
260 280 6
280 300 6
300 320 4
320 340 2
*/
