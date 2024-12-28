//Strassen's Matrix Multiplication.
#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices
void addMatrices(int N, int A[N][N], int B[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int N, int A[N][N], int B[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to multiply matrices
void multiplyMatrices(int N, int A[N][N], int B[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Strassen's Matrix Multiplication
void strassen(int N, int A[N][N], int B[N][N], int result[N][N]) {
    if (N == 1) {
        result[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = N / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    
    // Divide A and B into submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculate the 7 products using Strassen's formulas
    int P1[newSize][newSize], P2[newSize][newSize], P3[newSize][newSize], P4[newSize][newSize];
    int P5[newSize][newSize], P6[newSize][newSize], P7[newSize][newSize];
    
    int temp1[newSize][newSize], temp2[newSize][newSize];

    // P1 = (A11 + A22) * (B11 + B22)
    addMatrices(newSize, A11, A22, temp1);
    addMatrices(newSize, B11, B22, temp2);
    strassen(newSize, temp1, temp2, P1);

    // P2 = (A21 + A22) * B11
    addMatrices(newSize, A21, A22, temp1);
    strassen(newSize, temp1, B11, P2);

    // P3 = A11 * (B12 - B22)
    subtractMatrices(newSize, B12, B22, temp1);
    strassen(newSize, A11, temp1, P3);

    // P4 = A22 * (B21 - B11)
    subtractMatrices(newSize, B21, B11, temp1);
    strassen(newSize, A22, temp1, P4);

    // P5 = (A11 + A12) * B22
    addMatrices(newSize, A11, A12, temp1);
    strassen(newSize, temp1, B22, P5);

    // P6 = (A21 - A11) * (B11 + B12)
    subtractMatrices(newSize, A21, A11, temp1);
    addMatrices(newSize, B11, B12, temp2);
    strassen(newSize, temp1, temp2, P6);

    // P7 = (A12 - A22) * (B21 + B22)
    subtractMatrices(newSize, A12, A22, temp1);
    addMatrices(newSize, B21, B22, temp2);
    strassen(newSize, temp1, temp2, P7);

    // C11 = P1 + P4 - P5 + P7
    addMatrices(newSize, P1, P4, temp1);
    subtractMatrices(newSize, temp1, P5, temp2);
    addMatrices(newSize, temp2, P7, result);

    // C12 = P3 + P5
    addMatrices(newSize, P3, P5, temp1);
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            result[i][j + newSize] = temp1[i][j];
        }
    }

    // C21 = P2 + P4
    addMatrices(newSize, P2, P4, temp1);
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            result[i + newSize][j] = temp1[i][j];
        }
    }

    // C22 = P1 + P3 - P2 + P6
    addMatrices(newSize, P1, P3, temp1);
    subtractMatrices(newSize, temp1, P2, temp2);
    addMatrices(newSize, temp2, P6, temp1);
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            result[i + newSize][j + newSize] = temp1[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int N, int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N;
    
    printf("Enter the size of the matrix (NxN): ");
    scanf("%d", &N);

    // Input matrices A and B
    int A[N][N], B[N][N], result[N][N];
    
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Strassen's Matrix Multiplication
    strassen(N, A, B, result);

    printf("Resultant Matrix after Strassen's multiplication:\n");
    printMatrix(N, result);

    return 0;
}
