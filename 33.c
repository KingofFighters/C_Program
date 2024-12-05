//Program to print any multiplication table using while loop.
#include<stdio.h>
int main()
{
    int n, a=1, b;
    printf("Enter the number: ");
    scanf("%d", &n);
    
    while(a<20)
    {
        b = n * a;
        printf("%d * %d = %d\n",n,a,b);
        a++;
    }
}
