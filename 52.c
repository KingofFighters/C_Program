// Program to read a 2d array and print it with its sum //
#include<stdio.h>
int main()
{
    int a[2][2],i,j,sum=0;
    printf("Enter the array:");
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d ",a[i][j]);
            sum = sum + a[i][j];
        }
        printf("\n");
    }
    printf("Sum = %d", sum);
    printf("\n");
}