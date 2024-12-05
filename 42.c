//Program to print any symbol in descending order using for loop.
#include<stdio.h>
int main()
{
    int i,j;
    for(j=5;j>=0;j--)
    {
        for(i=0;i<j;i++)
        {
            printf("*");
        }
        printf("\n");
    }
}
//Program to print any symbol in ascending order.
#include<stdio.h>
int main()
{
    int i,j;
    for(j=0;j<5;j++)
    {
        for(i=0;i<=j;i++)
        {
            printf("+");
        }
        printf("\n");
    }
}