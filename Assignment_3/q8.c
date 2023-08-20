// Second highest element

#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int arr[MAX_SIZE];
    int i, size;
    int max, secondMax;

    printf("Enter the size of the array (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize max and secondMax
    max = arr[0];
    secondMax = arr[0];

    // Find the maximum element
    for (i = 1; i < size; i++) {
        if (arr[i] > max) {
            secondMax = max;
            max = arr[i];
        } else if (arr[i] > secondMax && arr[i] < max) {
            secondMax = arr[i];
        }
    }

    printf("The second highest element is: %d\n", secondMax);

    return 0;
}
