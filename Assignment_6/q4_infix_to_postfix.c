// Convert infix to postfix 

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

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

// Get the precedence of an operator
int getPrecedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    }
    return 0; // Default precedence for other characters
}

// Convert infix expression to postfix notation
void infixToPostfix(const char* infix, char* postfix) {
    struct Stack stack;
    initStack(&stack);
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        if (isalnum(current)) {
            postfix[j++] = current; // Operand, add to postfix
        } else if (current == '(') {
            push(&stack, current); // Open parenthesis, push to stack
        } else if (current == ')') {
            // Close parenthesis, pop and add operators to postfix until '(' is encountered
            while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.items[stack.top] == '(') {
                pop(&stack); // Discard the '('
            }
        } else {
            // Operator, pop operators with higher or equal precedence from stack to postfix
            while (!isEmpty(&stack) && getPrecedence(stack.items[stack.top]) >= getPrecedence(current)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, current); // Push the current operator onto the stack
        }
    }

    // Pop any remaining operators from stack to postfix
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strlen(infix) - 1] = '\0'; // Remove the newline character

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
