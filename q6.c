// Delete an element from the array

#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int arr[MAX_SIZE];
    int i, size, pos;

    printf("Enter the size of the array (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position of the element to delete (0 to %d): ", size - 1);
    scanf("%d", &pos);

    // Check if the position is valid
    if (pos < 0 || pos >= size) {
        printf("Invalid position!\n");
        return 0;
    }

    // Shift elements to the left
    for (i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrement the size of the array
    size--;

    printf("Array after deleting the element:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
