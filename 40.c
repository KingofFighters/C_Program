//Program to print the sum of entered positive numbers using for loop and continue.
#include<stdio.h>
int main()
{
    int i,sum=0,a;
    for(i=0;i<=5;i++)
    {
        printf("Enter a number:");
        scanf("%d", &a);
        if(a<0)
            continue;
        sum = sum + a;
    }
    printf("%d\n", sum);
} 