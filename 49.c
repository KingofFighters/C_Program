//Program to print the sum and average marks of 5 students.
#include<stdio.h>
int main()
{
    int i, marks[5],sum=0;
    float avg;
    printf("Enter the marks of the 5 students:");
    for(i=0;i<5;i++)
        scanf("%d", &marks[i]);
    for(i=0;i<5;i++)
        sum = sum + marks[i];
    printf("SUM : %d\n", sum);
    avg = sum/5;
    printf("The average of the five students is: %f\n",avg);
}
