//Program to print the index elements and array using for loops.
#include<stdio.h>
int main(){
    int i, b, a[100];
    printf("Enter the  size of the array: ");
    scanf("%d", &b);
    for(i=0;i<b;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The array is: ");
    for(i=0;i<b;i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for(i=0;i<b;i++)
    {
        printf("The element at index %d is %d\n",i,a[i]);
    }
    return 0;
}