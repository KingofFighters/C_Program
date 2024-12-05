// function with argument & no return type.
#include<stdio.h>
#include<stdlib.h>
void sum(int,float);
void main()
{
    int x;
    float y;
    printf("Enter x and y:");
    scanf("%d %f",&x,&y);
    sum(x,y);
}
void sum(int x,float y)
{
    printf("sum = %f", x+y);
}    