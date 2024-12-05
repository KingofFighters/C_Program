//Proram to reverse a string.
#include<stdio.h>
#include<string.h>
int main()
{
    char s1[30];
    printf("Enter the string:");
    fgets(s1,30,stdin);
    strrev(s1);
    printf("%s",s1);
}
//Program to reverse a string without using strrev().
#include<stdio.h>
#include<string.h>
int main()
{
    int l,i;
    char ch;
    char s1[30];
    printf("Enter the string:");
    fgets(s1,30,stdin);
    l = strlen(s1);
    for(i=0;i<l/2;i++)
    {
        ch = s1[i];
        s1[i] = s1[l-1-i];
        s1[l-1-i] = ch;
    }
    printf("%s",s1);
}