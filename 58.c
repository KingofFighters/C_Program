//'55.c' using do-while loop.
#include<stdio.h>
int main()
{
    int a[3][3], i, j, SR, SC, SD1 = 0, SD2 = 0;
    printf("Enter the elements of the array:\n");
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
    printf("The matrix is:\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    i = 0;
    do 
    {
        SD1 += a[i][i];
        SD2 += a[i][2-i];
        SR = SC = 0;
        for(j = 0; j < 3; j++)
        {
            SR += a[i][j];
            SC += a[j][i];
        }
        printf("SR%d=%d  SC%d=%d\n",i+1, SR,i+1, SC);
        i++;
    } 
    while(i < 3);
    printf("Sum of diagonal 1: %d\n", SD1);
    printf("Sum of diagonal 2: %d\n", SD2);
    return 0;
}
