#include <stdio.h>
int main()
{
    int a=8,b,c;
    b=(++a,a++);//a=10,b=9
    c=a++,++a;//c=10,a=12
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
}