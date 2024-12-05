//Program to print sum of some numbers using for loop(excluding negative numbers).
#include<stdio.h>
int main()
{
    int a, sum=0;
    for(int i=0;i<5;i++)
    {
        printf("Enter the positive number: ");
        scanf("%d",&a);
        if(a<0)
        break;
        sum = sum + a;
    }
    printf("SUM = %d", sum);
}