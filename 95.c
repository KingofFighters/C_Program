//Problem on recursion.
#include<stdio.h>
#include<stdlib.h>
void display(int n)
{
    if(n<1)
    return;
    else
    {
        printf("%d",n);
        display(n-1);
        printf("%d",n);
    }
}
int main()
{
    int n=3;
    display(n);
}