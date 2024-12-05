/*program to read an array of 10 integers and print total no. of even and odd numbers.*/
#include<stdio.h>
int main()
{
    int i,a[10];
    int odd=0,even=0;
    printf("Enter the array:");
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]%2==0)
            even++;
        else
            odd++;
    }    
    printf("The total number of even numbers =%d",even);
    printf("\nThe total number of odd numbers =%d",odd);
}