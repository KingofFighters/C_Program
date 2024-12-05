//Program to concatenate two strings.
#include<stdio.h>
#include<string.h>
int main()
{
    char a[30],b[20];
    printf("Enter the names:");
    scanf("%s %s",a,b);
    strcat(b,a);
    printf("%s",b);
}
/*Important: If we want to concatenate till some index then we can do that using
strncat(b,a,3);*/
//OR if we  want to do this program without using strcat then
#include<stdio.h>
#include<string.h>
int main()
{
    int len1,len2,i=0;
    char a[30],b[20];
    printf("Enter the names:");
    scanf("%s %s",a,b);
    len1 = strlen(a);
    len2 = strlen(b);
    while(i<=len2)                         
    {
        a[len1+i] = b[i];
        i++;
    }
    printf("After concatenation : %s",a);
    using for loop: 
    for(i=0;i<=len2;i++)
    {
        a[len1+i] = b[i];
    }  
} 