#include <stdio.h>
int main()
{
    int a=8,b;
    b=(a++,++a,a>>2);
    printf("%d\n", a);
    printf("%d\n", b);
}