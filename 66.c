//Program to compare two strings.
#include<stdio.h>
#include<string.h>
int main()
{
    int value;
    char S1[20];char S2[20];
    printf("Enter the first string:");
    fgets(S1,20,stdin);
    printf("Enter the second string:");
    scanf("%s",S2);
    value = strcmp(S1,S2);
    if(value==0)
        printf("Same");
    else
        printf("Not Same\n");
    printf("%d",value);
}

// Proram to compare two strings without using strcmp.
#include<stdio.h>
#include<string.h>
int main()
{
    int flag,i;
    char s1[40];char s2[50];
    printf("Enter the first string:");
    fgets(s1,40,stdin);
    printf("Enter the second string:");
    fgets(s2,50,stdin);
    for(i=0;s1[i]!='\0' || s2[i]!='\0';i++)
    {
        if(s1[i]!=s2[i])
        {   
            flag=1;
            break;
        }
        if(s1[i]==s2[i])
        {   
            flag=0;
            break;
        }
    }
    if(flag==1)
        printf("Not same"); 
    if(flag==0)
        printf("Same");
}