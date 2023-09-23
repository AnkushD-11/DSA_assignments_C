// Priority Queue

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int* arr;
    int* priorities;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    if (pq == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    pq->arr = (int*)malloc(capacity * sizeof(int));
    pq->priorities = (int*)malloc(capacity * sizeof(int));
    if (pq->arr == NULL || pq->priorities == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    pq->size = 0;
    pq->capacity = capacity;
    
    return pq;
}

int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

int isFull(PriorityQueue* pq) {
    return pq->size == pq->capacity;
}

void enqueue(PriorityQueue* pq, int value, int priority) {
    if (isFull(pq)) {
        printf("Priority queue is full. Cannot enqueue.\n");
        return;
    }
    
    int i = pq->size - 1;
    while (i >= 0 && priority > pq->priorities[i]) {
        pq->arr[i + 1] = pq->arr[i];
        pq->priorities[i + 1] = pq->priorities[i];
        i--;
    }
    
    pq->arr[i + 1] = value;
    pq->priorities[i + 1] = priority;
    pq->size++;
}

int dequeue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty. Cannot dequeue.\n");
        exit(1);
    }
    
    int value = pq->arr[0];
    for (int i = 1; i < pq->size; i++) {
        pq->arr[i - 1] = pq->arr[i];
        pq->priorities[i - 1] = pq->priorities[i];
    }
    
    pq->size--;
    
    return value;
}

void display(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty.\n");
        return;
    }
    
    printf("Priority queue elements (Highest Priority to Lowest Priority):\n");
    for (int i = 0; i < pq->size; i++) {
        printf("Value: %d, Priority: %d\n", pq->arr[i], pq->priorities[i]);
    }
}

void destroyPriorityQueue(PriorityQueue* pq) {
    free(pq->arr);
    free(pq->priorities);
    free(pq);
}

int main() {
    PriorityQueue* pq = createPriorityQueue(MAX_SIZE);
    
    enqueue(pq, 10, 3);
    enqueue(pq, 20, 2);
    enqueue(pq, 30, 1);
    enqueue(pq, 40, 2);
    
    display(pq);
    
    printf("Dequeued element: %d\n", dequeue(pq));
    
    display(pq);
    
    destroyPriorityQueue(pq);
    
    return 0;
}
