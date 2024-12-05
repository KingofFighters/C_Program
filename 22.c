#include<stdio.h>
#include<stdlib.h>
int main()
{
    int age;
    printf("Enter age:");
    scanf("%d",&age);
    if(age>25&&age<30)
    {
        printf("age=%d\n", age);
        printf("Coffee with me\n");
    }
    else
    printf("age=%d\n", age);
    printf("Go home\n");
    printf("Out of if-else\n");
}