//String as an argument.
#include<stdio.h>
void modify(char *,char *);

int main()
{
    char str1[] = "jenny";
    char str2[] = "lectures";
    modify(str1,str2);
    return 0;
}
void modify(char *str1,char *str2)
{
    int i,l=0;
for(i=0;str1[i]!='\0';i++)
{
    l= l+1;
}
str2[1]= 'z';
printf("length of string1 is: %d\n",l);
printf("both strings are: %s %s",str1,str2);
}