//Program to find the sum of its individual rows and columns of rectangular matrix.
#include<stdio.h>
int main() 
{
    int a[2][3], i, j, sum;
    printf("Enter the elements of the array:\n");
    for(i = 0; i < 2; i++) 
    {
        for(j = 0; j < 3; j++) 
            scanf("%d", &a[i][j]);
    }
    for(i = 0; i < 2; i++) 
    {
        sum = 0;
        for(j = 0; j < 3; j++) 
            sum = sum + a[i][j];
        printf("Sum of row %d = %d\n", i + 1, sum);
    }
    for(i = 0; i < 3; i++) 
    {
        sum = 0;
        for(j = 0; j < 2; j++)
            sum = sum + a[j][i];
        printf("SUM of column %d = %d\n", i + 1, sum);
    }
}
