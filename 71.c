//concept of pointer.
#include<stdio.h>
void main()
{
    int a=10,b=5;
    int *p,*q;//the variables and pointers datatype must be same.
    p=&a;
    q=&b;
    *q=*p;//q=p;
    printf("a=%d  %d  %d",a,*p,*q);
}