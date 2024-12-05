// If play.
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    if(age>=30)
    printf("You are a fucking oldy");

    if(age>20 && age<30)
    printf("You may fuck with me");

    if(age>15 && age<=20)
    printf("You are a kid");

    if(age>0 && age<15)
    printf("You may go home");
}