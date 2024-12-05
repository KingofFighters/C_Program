// function with no arguments & with return type.
#include<stdio.h>
#include<stdlib.h>
char sum(void);
void main()
{
    char s;
    s = sum();
    printf("sum = %c",s);
} 
char sum()
{
    int a=5,b=7,sum=0;
    sum= a + b;
    return 'a','0','1';
    return sum;
}