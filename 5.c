#include<stdio.h>
int main()
{
  int a =30, b, c, f;
  b = a++;
  c = --b;
  f = ++c;
  printf("%d\n%d\n%d\n%d\n", a, b, c, f);
}