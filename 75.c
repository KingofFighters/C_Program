#include<stdio.h>
int main()
{
    int a = -11;//const int a = -11; if constant term is given no one can change its value.
    int *p = &a;

    *p = 10;
    printf("%d",a);
}