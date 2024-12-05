// Program to compare the ascii values of two strings.
#include<stdio.h>
#include<string.h>
int main()
{
    int flag=0,i;
    char s1[40];char s2[50];
    printf("Enter the first string:");
    fgets(s1,40,stdin);
    printf("Enter the second string:");
    fgets(s2,50,stdin);
    
    if(strcmp(s1, s2) == 0) {
        printf("The two strings are equal");
    } else if(strcmp(s1, s2) > 0) {
        printf("s1 is greater than s2");
    } else {
        printf("s2 is greater than s1");
    }
    return 0;
}
