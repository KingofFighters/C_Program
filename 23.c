//Program to print whether a given number is positive or negative.
#include<stdio.h>
int main()
{
    int num;
    printf("Enter the number:");
    scanf("%d", &num);
    if(num > 0)
        printf("%d is positive integer\n", num);
    else
    {
        if(num < 0)
            printf("%d is negative integer\n", num);
        else
            printf("%d is ZERO", num);
    }
}
