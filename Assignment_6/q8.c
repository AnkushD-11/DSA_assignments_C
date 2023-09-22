// Convert binary to decimal 

#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

void decimalToBinary(int num) {
    Stack stack;
    initialize(&stack);

    while (num > 0) {
        int remainder = num % 2;
        push(&stack, remainder);
        num = num / 2;
    }

    printf("Binary representation: ");
    while (!isEmpty(&stack)) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}

int main() {
    int decimalNum;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);

    decimalToBinary(decimalNum);

    return 0;
}
