//Program to print whether a number is prime or not.
#include<stdio.h>
int main()
{
    int n, i, prime=1;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if(n<0)
    {
        printf("Invalid Input\n");
        prime = 0;
    }
    else
    {
        if(n<=1)
        {
            prime = 0;
        }
        else
        {
            for(i=2;i<=n/2;i++)
            {
                if(n%i == 0)
                {
                    prime = 0;
                    break;
                }
            }
        }
        if(prime == 1)
            printf("%d is a prime number: ",n);
        else
            printf("%d is not a prime number: ",n);
        return 0;
    }
}