//print sum of 5 numbers if negative value then continue using temporary variable.
#include <stdio.h>
int main()
{
    int i, sum = 0, a, tmp;
    for (i = 0; i < 5; i++)
    {
        tmp = i; // store current value of i
        printf("Enter a number: ");
        scanf("%d", &a);
        if (a < 0)
        {
            i = tmp - 1; // reset i to its previous value
            continue;
        }
        sum = sum + a;
    }
    printf("%d\n", sum);
    return 0;
}
