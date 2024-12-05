/* User defined functions(function declaration,calling and definition)
and it's related problems */
//Debugging is easy in this usable function or modules case.
#include<stdio.h>
#include<stdlib.h>
void sum();// function declaration
void fun();// function declaration
int main() 
{
    sum();// function calling
    fun();// function calling
}
void sum()// function definition
{
    int a, b, sum=0;
    printf("Enter two numbers:");
    scanf("%d %d", &a, &b);
    sum = a + b;
    printf("sum = %d\n", sum);
}
void fun()// function definition
{
    float x, y, T;
    printf("Enter two numbers:");
    scanf("%f %f", &x, &y);
    T = x + y;
    printf("%f\n", T);
}