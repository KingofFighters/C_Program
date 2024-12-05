//Program to store and print transpose  of a matrix.
#include<stdio.h>

#define ROWS 2
#define COLS 3

int main()
{
    int a[ROWS][COLS], b[COLS][ROWS];
    int i, j;
    
    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for(i = 0; i < COLS; i++) {
        for(j = 0; j < ROWS; j++) {
            b[i][j] = a[j][i];
        }
    }
    
    printf("Transpose of the matrix:\n");
    for(i = 0; i < COLS; i++) {
        for(j = 0; j < ROWS; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
