//Program to increase the salary according to age and salary.
#include<stdio.h>
int main()
{
    int age, salary;
    printf("Enter age and salary:");
    scanf("%d%d", &age, &salary);
    if(age>50 && salary<50000)
    {
        salary += 10000;
        printf("Salary:%d\n",salary);
    }
    else
        if(age<50 && salary>50000)
        {
            salary += 5000;
            printf("Salary:%d\n",salary);
        }
        else
        {
            salary +=40000;
            printf("Salary:%d\n",salary);
            printf("You are promoted congratulations\n");
        }    
}