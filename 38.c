//Program to print sum of some numbers using while loop.
#include<stdio.h>
int main()
{
    int a, i=0, sum=0;
    while(i<5)
    {
        printf("Enter the number: ");
        scanf("%d", &a);
        if(a<0)
        break;
        sum = sum + a;
        i++;
    }
    printf("SUM is: %d", sum);
}