// Application of function pointer.
#include <stdio.h>
#include <stdlib.h>

void add(int, int);
void sub(int, int);
void mult(int, int);
void divi(int, int);
void (*fptr[4])(int, int) = {add, sub, mult, divi};

void add(int a, int b) 
{
    printf("%d\n", a + b);
}
void sub(int a, int b) 
{
    printf("%d\n", a - b);
}
void mult(int a, int b) 
{
    printf("%d\n", a * b);
}
void divi(int a, int b) 
{
    if (b != 0) {
        printf("%d\n", a / b);
    } else {
        printf("Division by zero error!\n");
    }
}

int main() 
{
    int a, b, ch;
    printf("0 for add, 1 for sub, 2 for mult, 3 for div\n");
    printf("Enter choice: ");
    scanf("%d", &ch);
    if (ch < 0 || ch > 3) 
    {
        printf("Invalid choice!\n");
        return 1;
    }
    printf("Enter a, b: ");
    scanf("%d%d", &a, &b);
    fptr[ch](a, b);
    return 0; 
}
