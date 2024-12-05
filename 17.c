//Details about gaps and some mind plays. 
#include <stdio.h>
int main() {
    int a = 12345;
    float b = 2345.225;
    char c[30] = "Hrishi";
    printf("%010d\n", a);
    printf("%d%07d\n", a, 0);
    printf("%015.8f\n", b);
    printf("%0.3f\n", b);
    printf("%0.5f\n",b);
    printf("%9s\n", c);
    printf("%-8s", c);
    return 0;
}
