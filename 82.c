// program to find the max of two numbers using the context of arguments with return type.
#include<stdio.h>
#include<stdlib.h>
int max(int,int);
void main()
{
    int a,b,z;
    printf("Enter two numbers:");
    scanf("%d %d", &a,&b);
    z = max(a,b);
}
int max(int x,int y)
{
    if(x>y)
    {
        printf("%d is greater",x);
        return x;
    }
    else
    {
        printf("%d is greater",y);
        return y;
    }
}