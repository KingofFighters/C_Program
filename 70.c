//check of adress of and indirectional operator.
#include<stdio.h>
int main()
{
    int a=10,b=9,c;
    int *p,*q;
    p=&a,q=&b,c=*q,*p=20;
    printf("a=%d\n",a);     
    printf("a=%d\n",*p);    
    printf("Address of a = %x\n",&a);
    printf("Address of p = %x\n",&p);
    printf("c=%d\n",c);
    printf("a=%d\n",a);
    printf("%x\n",p);
}