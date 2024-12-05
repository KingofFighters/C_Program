//Program to take 5 inputs and print their sum using do-while loop.
#include<stdio.h>

int main() 
{
    int i = 0, sum = 0, a;
    do 
    {
        printf("Enter a number: ");
        scanf("%d", &a);
        if (a < 0) 
        {
            printf("Negative input is not allowed. Try again.\n");
        }
        else
        {
            sum += a;
            i++;
        }
    } 
    while (i < 5);
    printf("The sum of the first %d positive inputs is %d.\n", i, sum);
    return 0;
}
