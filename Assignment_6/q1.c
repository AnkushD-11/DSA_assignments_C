// Implementation of stack using array

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

bool isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1; // You might want to handle underflow differently
    }
    int value = stack->data[stack->top];
    stack->top--;
    return value;
}

int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1; // You might want to handle this case differently
    }
    return stack->data[stack->top];
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
 
    printf("Top element: %d\n", peek(&stack));

    while (!isEmpty(&stack)) {
        printf("Popped: %d\n", pop(&stack));
    }

    return 0;
}
