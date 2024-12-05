// no argument no return type.
#include<stdio.h>
#include<stdlib.h>
int ch;           //global variable
void sum(void);
void subtract(void);
void multiply(void);
void divide(void);
int main() 
{
    sum();
    subtract();
    multiply();
    divide();
}
void sum()
{
    int a, b, sum=0,fuck=0;
    printf("Enter two numbers for addition:");
    scanf("%d %d", &a, &b);
    sum = a + b;
    printf("sum = %d\n", sum);
    printf("Enter a character:");
    scanf(" %d",&ch);
    fuck= a + ch;
    printf("%d + %d= %d\n",a,ch,fuck);
}
void subtract()
{
    int a, b, sub=0;
    printf("Enter two numbers for subtraction:");
    scanf("%d %d", &a, &b);
    sub = a - b;
    printf("sub = %d\n", sub);
}
void multiply()
{
    int a, b, mul=0;
    printf("Enter two numbers for multiplication:");
    scanf("%d %d", &a, &b);
    mul = a * b;
    printf("mul = %d\n", mul);
}
void divide()
{
    int a, b, div=0;
    printf("Enter two numbers for division:");
    scanf("%d %d", &a, &b);
    div = a / b;
    printf("div = %d\n", div);
}