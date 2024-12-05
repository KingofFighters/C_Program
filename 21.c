//Program to read and print some texts.
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int age;
    printf("Enter your age:");
    scanf("%d",&age);
    
    if(age>18)
        printf("Your age is=%d \nYou can watch porn\nYou can masturbate\n", age);
    else
        printf("Go and study kid");
    return 0;
}