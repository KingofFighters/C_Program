//LCS.
#include <stdio.h>
#include <string.h>

// Function to find the length of LCS using dynamic programming
int LCS(char* X, char* Y) {
    int m = strlen(X);
    int n = strlen(Y);
    
    // Create a 2D array to store lengths of LCS
    int L[m+1][n+1];
    
    // Build the LCS table in a bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;  // Base case: LCS of an empty string with any string is 0
            } else if (X[i-1] == Y[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;  // If characters match, increment the LCS length
            } else {
                L[i][j] = (L[i-1][j] > L[i][j-1]) ? L[i-1][j] : L[i][j-1];  // Take the maximum value
            }
        }
    }
    
    // The length of the LCS is stored in L[m][n]
    return L[m][n];
}

// Function to print the LCS
void printLCS(char* X, char* Y) {
    int m = strlen(X);
    int n = strlen(Y);
    
    // Create a 2D array to store lengths of LCS
    int L[m+1][n+1];
    
    // Build the LCS table in a bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i-1] == Y[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
            } else {
                L[i][j] = (L[i-1][j] > L[i][j-1]) ? L[i-1][j] : L[i][j-1];
            }
        }
    }
    
    // Now we trace back the LCS from the table
    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';  // Null terminate the LCS string
    
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs[index-1] = X[i-1];  // If characters match, add it to the LCS
            i--;
            j--;
            index--;
        } else if (L[i-1][j] > L[i][j-1]) {
            i--;  // Move up in the table if the value is greater in the upper cell
        } else {
            j--;  // Move left if the value is greater in the left cell
        }
    }
    
    // Print the LCS
    printf("Longest Common Subsequence: %s\n", lcs);
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    
    // Find the length of LCS
    int length = LCS(X, Y);
    printf("Length of LCS: %d\n", length);
    
    // Print the LCS
    printLCS(X, Y);
    
    return 0;
}
