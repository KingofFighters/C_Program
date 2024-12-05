//Program to print the multiplication table of any number using for loop. 
#include<stdio.h>
int main()
{
    int num, a, b=0;
    printf("Enter a number: ");
    scanf("%d", &num);
    for(a=1; a<11; a++)
    {
        b= num * a;
        printf("%d * %d = %d\n", num, a, b);
    }
}
    