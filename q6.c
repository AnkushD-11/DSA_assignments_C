// Interchange rows

#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Function to interchange two rows of a matrix
void interchangeRows(int matrix[MAX_ROWS][MAX_COLS], int row1, int row2, int cols) {
    for (int j = 0; j < cols; j++) {
        int temp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp;
    }
}

int main() {
    int rows, cols;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    if (rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Invalid matrix size!\n");
        return 1;
    }

    int matrix[MAX_ROWS][MAX_COLS];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int row1, row2;
    printf("Enter the two row numbers to interchange (0-based index): ");
    scanf("%d %d", &row1, &row2);

    if (row1 < 0 || row1 >= rows || row2 < 0 || row2 >= rows) {
        printf("Invalid row numbers!\n");
        return 1;
    }

    // Interchange rows
    interchangeRows(matrix, row1, row2, cols);

    printf("\nMatrix after interchanging rows %d and %d:\n", row1, row2);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
