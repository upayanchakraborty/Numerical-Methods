#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//define your function here
float f(float x,float y)
{
return x*x+y*y;
}
//main function
void main ()
{
//declare variables
float x0,y0,h,k,k1,k2,k3,k4,x,y,yn,xf;
int count=1;
//inputs
printf("Please enter the value of x0: ");
scanf("%f",&x0);
printf("Please enter the value of y0: ");
scanf("%f",&y0);
printf("Please enter the value of h: ");
scanf("%f",&h);
printf("please enter the x value where we need to find y: ");
scanf("%f",&xf);
//for printing the table
printf("\niteration\tk1\t\tk2\t\tk3\t\tk4\t\tyn\n");
//Runge-Kutta Method
while(x0<xf){
k1=h*f(x0,y0);
k2=h*f((x0+h/2),(y0+k1/2));
k3=h*f((x0+h/2),(y0+k2/2));
k4=h*f((x0+h),(y0+k3));
yn=(k1+(2*k2)+(2*k3)+k4)*1/6+y0;
printf("%d\t\t%f\t%f\t%f\t%f\t%f\n",count,k1,k2,k3,k4,yn);
x0=x0+h;
y0=yn;
count++;
}
//output
printf("The value of y is: %f",yn);
}
