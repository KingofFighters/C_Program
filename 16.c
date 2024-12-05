//Program to print different types of datatype
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a;
    float b;
    char *ch = malloc(100*sizeof(ch));
    printf("Enter the values:");
    scanf("%d %f %s", &a, &b, ch);
    printf("Your entered values are:");
    printf("a=%d\n b=%f\n ch=%s",a,b,ch);
    free(ch);
    return 0;
}