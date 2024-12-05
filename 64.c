// Program to count a string.
#include<stdio.h>
#include<string.h>
int main()
{
    int count=0;
    char name[30];
    printf("Enter the name:");//puts(Enter the name:);
    fgets(name,30,stdin);     //if i write gets here instead of fgets then it will take all input whatever u give and overwrite your memory//
                              // or scanf("%s",name);
    puts(name);               // if we write this printf("%s",&name[2]); then the output will start from the index 2 of your input
                              //puts() uses new line after end of it
    count = strlen(name);     // length of the input string
    printf("String lenth is %d",count);
}
// or if u dont wanna use strlen u can do this instead
#include<stdio.h>
int main()
{
    int i=0,count=0;
    char name[30];
    printf("Enter the name:");
    fgets(name,30,stdin);
    puts(name);
    while(name[i]!='\0')
    {
        count++;
        i++;
    }
    printf("Length of the string is %d",count);
} 