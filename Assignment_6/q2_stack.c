//Implement stack using linked list

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void initialize(Stack *stack) {
    stack->top = NULL;
}

bool isEmpty(Stack *stack) {
    return stack->top == NULL;
}

void push(Stack *stack, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1; // You might want to handle this case differently
    }
    int value = stack->top->data;
    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1; // You might want to handle this case differently
    }
    return stack->top->data;
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    while (!isEmpty(&stack)) {
        printf("Popped: %d\n", pop(&stack));
    }

    return 0;
}
