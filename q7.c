// Write a program to reverse a string.

#include <stdio.h>
#include <string.h>

// Function to reverse the string
void reverseString(char str[]) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    // Swap characters from the beginning and end of the string until they meet in the middle
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character at the end of the string (if present)
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
