#include<stdio.h>
int main()
{
    int a=10,b=6,c,d,e;
    c=a>>2;
    d=a<<2;
    e=~a;
    printf("%d\n",a&b);
    printf("%d\n",a|b);
    printf("%d\n",a^b);
    printf("%d\n",a&b&&b+1||0&&a*b++);
    printf("%d\n",c);
    printf("%d\n",d);
    printf("%d\n",e);
    printf("%d\n",(a+1)<<2);
    printf("%d\n",(a+2)>>2);
    printf("%d\n",~(a+3));
}