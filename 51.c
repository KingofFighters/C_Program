//program to read 2arrays of size5 & store sum of these arrays into third array and print it.
#include<stdio.h>
int main()
{
    int i,a[5],b[5],c[5];
    printf("Enter the first array:");
    for(i=0;i<5;i++)
        scanf("%d", &a[i]);
    printf("Enter the second array:");
    for(i=0;i<5;i++)
        scanf("%d", &b[i]);
    printf("The sum of the two arrays:");
    for(i=0;i<5;i++)
    {
        c[i]= a[i]+b[i];
        printf("%d ",c[i]);
    }
    printf("\n");
}
