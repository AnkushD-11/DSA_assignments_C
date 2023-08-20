// Remove duplicate elements

#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int arr[MAX_SIZE];
    int i, j, k, size;

    printf("Enter the size of the array (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Remove duplicate elements
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size;) {
            if (arr[j] == arr[i]) {
                // Shift elements to the left to overwrite duplicate element
                for (k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                // Decrement the size of the array
                size--;
            } else {
                j++;
            }
        }
    }

    printf("Array after removing duplicates:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
