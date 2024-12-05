//return string from a function & modify.
#include<stdio.h>

char* display();     //function declaration
int main()
{
    char* str;
    str = display();            //function calling
    str[0]='Z';
    printf("String is: %s",str);
}
char* display()                //function definition
{
    static char str[]="jenny";
    return str;
}