// Reverse a string using recursion and iteration.
// Iteration.
#include<stdio.h>
#include<string.h>

void reversestring(char *str)
{
    int i,j;
    char temp;
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--)
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
}

int main()
{
    char inputstring[100];
    printf("Enter a string:");
    scanf("%s", inputstring);
    reversestring(inputstring);
    printf("Reversed String: %s\n", inputstring);
    return 0;
}


//Recursion.
#include <stdio.h>
#include <string.h>

void reversestring(char str[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reversestring(str, start + 1, end - 1);
}

int main()
{
    char str[] = "Hello World!";
    int length = strlen(str);
    printf("Original String: %s\n", str);
    reversestring(str, 0, length - 1);
    printf("Reversed String: %s\n", str);
    return 0;
}
