//Gate question.
#include<stdio.h>
#include<stdlib.h>
void f(int *p, int *q)              //function definition
{
    p=q;
    *p=2;
}
int i=0, j=1;
int main()
{
    f(&i, &j);                       //function calling
    printf("%d%d\n",i,j);
    getchar();
    return 0;
}