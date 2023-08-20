// Write a program to implement searching and sorting in a given list of words.

#include <stdio.h>
#include <string.h>

// Function to perform linear search in the word list
int linear_search(char *word_list[], int size, char *target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(word_list[i], target) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char *words[] = {"apple", "orange", "banana", "grape", "kiwi", "pear"};
    int size = sizeof(words) / sizeof(words[0]);

    printf("Original List: ");
    for (int i = 0; i < size; i++) {
        printf("%s ", words[i]);
    }
    char *target_word = "kiwi";         //change targeted word
    int index = linear_search(words, size, target_word);
    printf("\n\nLinear Search:\n");
    if (index != -1) {
        printf("'%s' found at index %d.\n", target_word, index);
    } else {
        printf("'%s' not found in the list.\n", target_word);
    }
}