//Program using strlwr() function.
#include<stdio.h>
#include<string.h>
int main()
{
    char s1[20];
    printf("Enter the string:");
    scanf("%s", s1);
    strlwr(s1);
    printf("%s", s1);
}
//Program without using strlwr() function.
#include<stdio.h>
int main()
{
    int i;
    char s1[30];
    printf("Enter the string:");
    scanf("%s", s1);
    for(i=0;s1[i]!='\0';i++)
    {
        if(s1[i]>='A' && s1[i]<='Z')
        {
            s1[i] = s1[i] + 32;
        }
    }
    printf("%s", s1);
}