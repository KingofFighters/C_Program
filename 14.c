#include <stdio.h>
int main()
{
   int a=0, b=1, c=-1, z;
   z= (--a*(5+b)/2-c++*b);
   printf("%d\n", z);//z=-3
}  