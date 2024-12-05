// Using a pointer to call a function.
#include<stdio.h>
#include<stdlib.h>
int sum(int,int);
int main()
{
    int s=0;
    int(*ptr)(int,int) = &sum;
    s = (*ptr)(2,3);
    printf("%d",s);
}
int sum(int a, int b)
{
    return a+b;
}