// Write a program to insert a new element in array at given location k

#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int arr[MAX_SIZE];
    int i, size, num, k;

    printf("Enter the size of the array (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to insert: ");
    scanf("%d", &num);

    printf("Enter the position to insert (0 to %d): ", size);
    scanf("%d", &k);

    // Check if the position is valid
    if (k < 0 || k > size) {
        printf("Invalid position!\n");
        return 0;
    }

    // Shift elements to the right
    for (i = size - 1; i >= k; i--) {
        arr[i + 1] = arr[i];
    }

    // Insert the new element
    arr[k] = num;

    // Increment the size of the array
    size++;

    printf("Array after inserting the element:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
