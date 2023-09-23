// Dequeue

#include <stdio.h>
#include <stdlib.h>

// Structure for a deque node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Structure for the deque
typedef struct {
    Node* front;
    Node* rear;
} Deque;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to create a new deque
Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    if (deque == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

// Function to check if the deque is empty
int isEmpty(Deque* deque) {
    return deque->front == NULL;
}

// Function to insert an element at the front of the deque
void insertFront(Deque* deque, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

// Function to insert an element at the rear of the deque
void insertRear(Deque* deque, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

// Function to remove an element from the front of the deque
int removeFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot remove from front.\n");
        exit(1);
    }
    int data = deque->front->data;
    Node* temp = deque->front;
    if (deque->front == deque->rear) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }
    free(temp);
    return data;
}

// Function to remove an element from the rear of the deque
int removeRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot remove from rear.\n");
        exit(1);
    }
    int data = deque->rear->data;
    Node* temp = deque->rear;
    if (deque->front == deque->rear) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
    }
    free(temp);
    return data;
}

// Function to display the elements of the deque from front to rear
void display(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }
    Node* current = deque->front;
    printf("Deque elements (Front to Rear): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to destroy the deque and free memory
void destroyDeque(Deque* deque) {
    Node* current = deque->front;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(deque);
}

int main() {
    Deque* deque = createDeque();

    insertFront(deque, 10);
    insertRear(deque, 20);
    insertFront(deque, 5);
    display(deque);

    printf("Removed from front: %d\n", removeFront(deque));
    printf("Removed from rear: %d\n", removeRear(deque));
    display(deque);

    insertRear(deque, 15);
    insertFront(deque, 25);
    display(deque);

    destroyDeque(deque);

    return 0;
}
