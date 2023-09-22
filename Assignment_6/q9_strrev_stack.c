#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char arr[MAX_SIZE];
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to push a character onto the stack
void push(struct Stack *stack, char c) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = c;
}

// Function to pop a character from the stack
char pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->arr[stack->top--];
}

// Function to reverse a string using a stack
void reverseString(char *inputString) {
    int length = strlen(inputString);
    struct Stack stack;
    initialize(&stack);

    // Push each character of the input string onto the stack
    for (int i = 0; i < length; i++) {
        push(&stack, inputString[i]);
    }

    // Pop characters from the stack to build the reversed string
    for (int i = 0; i < length; i++) {
        inputString[i] = pop(&stack);
    }
}

int main() {
    char inputString[] = "Meow";
    printf("Original string: %s\n", inputString);

    reverseString(inputString);

    printf("Reversed string: %s\n", inputString);

    return 0;
}
