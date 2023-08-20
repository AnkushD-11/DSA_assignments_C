// Snake sequence
/* A snake sequence is defined as a sequence of numbers where each new number, which can
only be located to the right or down of the current number, is either plus or minus one */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the maximum length snake sequence
int maxSnakeSequence(int mat[MAX_SIZE][MAX_SIZE], int n) {
    int dp[MAX_SIZE][MAX_SIZE];
    int maxLen = 1; // Minimum length of the snake sequence is 1

    // Initialize the dp matrix with 1
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 1;

    // Traverse the matrix from the bottom right to the top left
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            // Check if the cell is adjacent and has a difference of 1 with its neighbors
            if ((abs(mat[i][j] - mat[i][j + 1]) == 1) || (abs(mat[i][j] - mat[i + 1][j]) == 1)) {
                dp[i][j] = 1 + max(dp[i][j + 1], dp[i + 1][j]);
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }

    return maxLen;
}

int main() {
    int n;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid matrix size!\n");
        return 1;
    }

    int matrix[MAX_SIZE][MAX_SIZE];

    printf("Enter the elements of the square matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    int result = maxSnakeSequence(matrix, n);
    printf("Maximum length of the snake sequence is: %d\n", result);

    return 0;
}

