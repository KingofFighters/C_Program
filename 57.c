//'55.c' and printing diagonal elements with while loop.
#include<stdio.h>
int main()
{
    int a[3][3],i,j,SR,SC,SD1=0,SD2=0;
    printf("Enter the elements of the array:\n");
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
    i=0,j=0;
    while(i<3 && j<3)
    {
        SD1 = SD1 + a[i][j];
        SD2 = SD2 + a[i][2-j];
        i++;
        j++;
    }
    printf("\nSD1=%d  SD2=%d\n",SD1,SD2);
    for(i=0;i<3;i++)
    {
        SR=SC=0;
        for(j=0;j<3;j++)
            {
            SR = SR + a[i][j];
            SC = SC + a[j][i];
            }
        printf("\nSR%d=%d  SC%d=%d\n",i+1,SR,i+1,SC);
    }
}
