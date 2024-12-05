//concept of more than one pointers.
#include<stdio.h>
void main()
{
    int a=10;
    int *p=&a;
    int **q=&p;
    printf("a=%d  %d  %d",a,*p,**q);
}