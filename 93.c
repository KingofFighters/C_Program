// Callback function. dislay is the callback function.
#include<stdio.h>
#include<stdlib.h>
void sum(int a, int b)
{
    printf("sum=%d\n",a+b);
}
void sub(int a, int b)
{
    printf("sub=%d\n",a-b);
}
void display(void(*fptr)(int,int));
int main()
{
    display(sum);
    display(sub);
}
void display(void(*fptr)(int,int))
{
    (*fptr)(5,1);
}