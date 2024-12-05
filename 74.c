//Mix operations on pointers.
#include<stdio.h>
int main()
{
    int a[]= {10,11,-1,56,67,5,4};
    int *p,*q;
    p=a;
    printf("%d\n",*p);
    printf("%d %d %d\n",(*p)++,*p++,*++p);  //right to left execution but bracket first preference

    q= p+3;
    printf("%d\n",*q-3);
    printf("%d\n",*--p+5);
    printf("%d\n",*p + *q);
}