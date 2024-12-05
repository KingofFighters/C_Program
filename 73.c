//concept of add, subtract, and increment/decrement in pointers.
#include<stdio.h>
int main()
{
    int a[]= {50,1,-1,10,11};
    int *p = &a[0];
    int *q = &a[4];
    int d;

    d= p-q;
    printf("%d\n",d);
    *q= 25;
    d= q-p;
    printf("%d\n",d);
    *p= 27;
    q= q-3;
    printf("%d\n",*q);
    p= p+3;
    printf("%d\n",*p);
    d= p-q;
    printf("%d\n",d);
    *p--;
    printf("%d\n",*p);
    *++p;
    printf("%d\n",*p);
}