#include<stdio.h>
#include<math.h>
float f(float x, float y)
{
    return 3*x + y*y;
}
void main()
{
    int i;
    float y,xi,yi,xf,h;
    printf("Enter the initial condition for x: ");
    scanf("%f",&xi);
    printf("Enter the initial condition for y: ");
    scanf("%f",&yi);
    printf("Enter the value of x for which y is required: ");
    scanf("%f",&xf);
    printf("Enter the step-width h: ");
    scanf("%f",&h);
    printf("xi\t\tyi\t\tf(xi,yi)\th*f(xi,yi)\ty+hy\n");
    printf("_______________________________________________________________________________________\n");
    while(xi<xf)
    {
        y=yi+h*f(xi,yi);
        printf("%f\t%f\t%f\t%f\t%f\n",xi,yi,f(xi,yi),h*f(xi,yi),y);
        yi=y;
        xi=xi+h;
    }
    printf("%f\t%f\n",xi,yi);
    printf("_______________________________________________________________________________________\n");
    printf("The value of y is %f\n\n",y);
}
