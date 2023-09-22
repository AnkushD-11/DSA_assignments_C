// Check the number of opening and closing parenthesis are equal or not.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// Define a stack structure
struct Stack {
    char items[MAX_SIZE];
    int top;
};

// Initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Push an element onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top < MAX_SIZE - 1) {
        stack->items[++stack->top] = item;
    }
}

// Pop an element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    }
    return '\0'; // Return null character for an empty stack
}

// Check if parentheses are balanced
bool areParenthesesBalanced(const char* str) {
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            push(&stack, str[i]);
        } else if (str[i] == ')') {
            if (isEmpty(&stack)) {
                return false; // Unmatched closing parenthesis
            }
            pop(&stack);
        }
    }

    return isEmpty(&stack); // If stack is empty, parentheses are balanced
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0'; // Remove the newline character

    if (areParenthesesBalanced(str)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are not balanced.\n");
    }

    return 0;
}
