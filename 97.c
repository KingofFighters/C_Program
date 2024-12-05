//Basic pointers.
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a=10, b=9;
    int *p, *q;
    p= &a;
    q= &b;
    int c= *q;

    printf("Value of a = %d\n",a);
    printf("a= %d\n", *p);
    printf("Address of a = %x\n",&a);
    printf("Address of a = %x\n",p);
    printf("Address of p = %x\n",&p);
    printf("c = %d\n",c);
    printf("a = %d\n",a);
    printf("%x\n",p);
}