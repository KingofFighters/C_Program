//59.c using do-while loop
#include <stdio.h>

int main()
{
    int i = 0, j = 0, a[2][3], b[2][3], c[2][3];
    printf("Enter the first matrix:\n");
    do {
        do {
            scanf("%d", &a[i][j]);
            j++;
        } while (j < 3);
        
        i++;
        j = 0;
    } while (i < 2);
    
    i = j = 0;
    
    printf("Enter the second matrix:\n");
    do {
        do {
            scanf("%d", &b[i][j]);
            j++;
        } while (j < 3);
        
        i++;
        j = 0;
    } while (i < 2);
    
    i = j = 0;
    
    printf("The sum of matrices is:\n");
    do {
        do {
            c[i][j] = a[i][j] + b[i][j];
            printf("%d ", c[i][j]);
            j++;
        } while (j < 3);
        
        printf("\n");
        i++;
        j = 0;  
    } while (i < 2);
    
    return 0;
}
