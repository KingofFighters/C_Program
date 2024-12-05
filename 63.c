// Multiplication of matrices.
#include<stdio.h>
#define Q 20
int main()
{
    int i,j,k,a[Q][Q],b[Q][Q],c[Q][Q],sum,m,n,p,q;
    printf("Enter the rows and columns of first matrix:");
    scanf("%d %d", &m, &n);
    printf("Enter the first matrix:");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d", &a[i][j]);
    printf("Enter the rows and columns of second matrix:");
    scanf("%d %d", &p, &q);
    printf("Enter the second matrix:");
    for(i=0;i<p;i++)
        for(j=0;j<q;j++)
            scanf("%d", &b[i][j]);
    printf("First matrix = ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i>0 && j==0)
            {
                printf("%16d",a[i][j]);
                printf(" ");
            }
            else
            {
                printf("%d",a[i][j]);
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("Second matrix = ");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            if(i>0 && j==0)
            {
                printf("%17d",b[i][j]);
                printf(" ");
            }
            else
            {
                printf("%d",b[i][j]);
                printf(" ");
            }
        }
        printf("\n");
    }
    if(n!=p)
        printf("Cannot multiply");
    else
        {
            for(i=0;i<m;i++)
                for(j=0;j<q;j++)
                    {
                        sum=0;
                        for(k=0;k<n;k++)//upper bound of k should be equal to either columns of first matrix or rows of second matrix.
                            sum = sum + a[i][k]*b[k][j];
                        c[i][j] = sum;
                    }
            printf("\nThe resultant product matrix = ");
            for(i=0;i<m;i++)
                {
                    for(j=0;j<q;j++)
                        {
                            if(i>0 && j==0)
                            {
                                printf("%32d",a[i][j]);
                                printf(" ");
                            }
                            else
                            {
                                printf("%d",a[i][j]);
                                printf(" ");
                            }
                        }
                    printf("\n");
                }
        }
}
