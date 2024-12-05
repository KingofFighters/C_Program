#include<stdio.h>

int main() 
{
    int num1, num2, result;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    // Add a space before %c to consume any leading whitespace characters
    char operator;
    printf("Enter the operation you want to perform: ");
    scanf(" %c", &operator);

    switch (operator) 
    {
        case '+': 
            result = num1 + num2;
            printf("%d + %d = %d", num1, num2, result);
            break;
        case '-': 
            result = num1 - num2;
            printf("%d - %d = %d", num1, num2, result);
            break;
        case '*': 
            result = num1 * num2;
            printf("%d * %d = %d", num1, num2, result);
            break;
        case '/': 
            if (num2 == 0)
                printf("Undefined.");
            else {
                result = num1 / num2;
                printf("%d / %d = %d", num1, num2, result);
            }
            break;
        default:
            printf("Invalid operation.");
    }

    return 0;
}