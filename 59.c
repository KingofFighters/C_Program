//Program to read two matrices and store it in another matrix and print the new matrix.
#include<stdio.h>
int main()
{
    int i,j,a[2][3],b[2][3],c[2][3];
    printf("Enter the first matrix:");
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
            scanf("%d",&a[i][j]);
    printf("Enter the second matrix:");
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
            scanf("%d",&b[i][j]);
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            c[i][j]= a[i][j]+b[i][j];
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}
