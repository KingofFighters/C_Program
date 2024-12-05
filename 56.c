//Program to read and print a 3*3 matrix and print the individual sum of rows, columns and diagonals.
#include<stdio.h>
int main()
{
    int a[3][3],i,j,SR,SC,SD1=0,SD2=0;
    printf("Enter the elements of the matrix:\n");
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d",&a[i][j]);
    printf("The matrix is:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    for(i=0;i<3;i++)
    {
        SR=SC=0;
        for(j=0;j<3;j++)
            {
            SR = SR + a[i][j];
            SC = SC + a[j][i];
            if (i == j) // check if on the diagonal
                SD1 += a[i][j];
            if (i + j == 2) // check if on the other diagonal
                SD2 += a[i][j];
            }
        printf("SR%d=%d  SC%d=%d\n",i+1,SR,i+1,SC);
    }
    printf("SD1= %d SD2= %d ",SD1,SD2);
}