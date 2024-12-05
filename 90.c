//return pointer from function.
#include<stdio.h>
int * returnPointer(int[]);             //function declaration
int main()
{
    int a[]= {1,2,3,4,5},*p;
    p = returnPointer(a);                   //function calling
    printf("%d\n",*p);
}
int * returnPointer(int a[])               //function definition
{
    a= a+2;
    return a;
}