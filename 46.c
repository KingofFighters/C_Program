//Play like 45.c.
#include<stdio.h>
int main()
{
    int i=1,j=3;
    do
    {
        do
        {
            printf("%d",--j);
        }
        while(j>0);
        printf("%d",i++);
    }
    while(i<4);
    return 0;
}