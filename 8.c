#include <stdio.h>
int main()
{
    int a=10,b=5;
    int r1=(a==b&&b<a);
    int r2=(a>b&&b!=10&&b<11&&a>5);
    printf("%d\n", r1);
    printf("%d\n", r2);
}