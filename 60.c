//59.c using while loop.
#include<stdio.h>
int main()
{
    int i=0,j=0,a[2][3],b[2][3],c[2][3];
    printf("Enter the first matrix:");
    while(i<2)
    {
        j=0;
        while(j<3)
        {
            scanf("%d",&a[i][j]);
            j++;
        }
        i++;
    }
    i=0;j=0;
    printf("Enter the second matrix:");
    while(i<2)
    {
        j=0;
        while(j<3)
        {
            scanf("%d",&b[i][j]);
            j++;
        }
        i++;
    }
    i=0;j=0;
    printf("The resultant matrix is:\n");
    while(i<2)
    {
        j=0;
        while(j<3)
        {
            c[i][j]= a[i][j]+b[i][j];
            printf("%d ",c[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}
