/*Topic: void pointer, null pointer, dangling pointer, wild pointer


VOID pointer is a pointer which can store any datatype.
we cannot de-reference a void pointer.
E.g.,suppose in a program we are using three pointer datatype but if we use use void pointer
we dont need to take three pointers.


int a=5;
float b=2.1;
char c='0';

int *ip;             alternative            void vp;
float *fp;                                   vp=&a;
char *cp;                                    printf("%d",*(int*)vp);
ip=&a;                                       vp=&b;
fp=&b;                                       printf("%d",*(float*)vp;
cp=&c;                                       vp=&c;
printf("%d",*ip);                            printf("%d",*(char*)vp);
printf("%f",*fp);
printf("%c",*cp);

that's the advantage of using void pointer.
malloc and calloc functions returns void pointer.
*/


#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a = 5;
    void *vp;
    vp = &a;
    printf("%d",*(int *)vp);
}


/*
NULL pointer is a pointer which contains 0 or null value.
we cannot de-reference a null pointer.
null pointer doesn't point to any valid address.
If we doesnt initialize with value = null then our program may crash while execution
if by any chance pointer is dereferenced.....
It is used in error handling.
E.g.,*/


#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *ptr = NULL;
    printf("%d", ptr);
}


/*A pointer is called DANGLING pointer if the pointer had some previous memory address 
which has been freed now but it still points to that previous location which has some 
garbage value now.
Dangling pointer acts only within/inside the same function.
If inside any function we use static value as like in this example: 


int *f()
{
    static int a=10;
    return &a;
}
then even outside the int *f() function we can use the value of a.
E.g.,*/


#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *ptr1 = (int *)malloc(sizeof(int));
    *ptr1 = 10;
    printf("%d",*ptr1);
    free(ptr1);
    printf("%d",*ptr1);
}


/*WILD pointer is a pointer which is uninitialized or which points to any random memory location.
To overcome this wildness, we can either allocate memory with NULL or allocate memory later with
dynamic memory locaton.
E.G.,
int *fp;   
*/