//Proram to print grade of a student according to marks.
#include<stdio.h>
int main()
{
    int marks;
    float p;
    printf("Enter the marks of the student: ");
    scanf("%d", &marks);
    float c = marks;
    p = (c/100)*100;

    switch(marks/10)
    {
        case 9: printf("Your grade is: A+\n");
                printf("Your percentage is: %0.2f", p);
                break;
        case 8: printf("Your grade is: A\n");
                printf("Your percentage is: %0.2f", p);
                break;
        case 7: printf("Your grade is: B+\n");
                printf("Your percentage is: %0.2f", p);
                break;
        case 6: printf("Your grade is: B\n");
                printf("Your percentage is: %0.2f", p);
                break;
        case 5: printf("Your grade is: C+\n");
                printf("Your percentage is: %0.2f", p);
                break;
        case 4: printf("Your grade is: C\n");
                printf("Your percentage is: %0.2f", p);
                break;
        default:
                printf("You have failed.");
    }
}