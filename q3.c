// Rotating a matrix by 90

#include<stdio.h>
#define N 4
// Function to rotate a matrix by 90 degrees clockwise
void rotateClockwise(int matrix[][N]) {
    // Step 1: Transpose the matrix
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    
    // Step 2: Reverse each row
    for (int i = 0; i < N; i++) {
        for (int j = 0, k = N - 1; j < k; j++, k--) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][k];
            matrix[i][k] = temp;
        }
    }
}

void printarr(int arr[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }
}

int main(){
    int arr[N][N] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    rotateClockwise(arr);
    printarr(arr);
    return 0;
}