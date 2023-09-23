// Circular Queue

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int* arr;
    int front;
    int rear;
    int size;
} CircularQueue;

CircularQueue* createQueue() {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->arr = (int*)malloc(MAX_SIZE * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = MAX_SIZE;
    return queue;
}

int isFull(CircularQueue* queue) {
    return ((queue->rear + 1) % queue->size) == queue->front;
}

int isEmpty(CircularQueue* queue) {
    return queue->front == -1;
}

void enqueue(CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear = (queue->rear + 1) % queue->size;
    queue->arr[queue->rear] = value;
}

int dequeue(CircularQueue* queue) {
    int data;
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    data = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->size;
    }

    return data;
}

void display(CircularQueue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (i = queue->front; i != queue->rear; i = (i + 1) % queue->size)
        printf("%d ", queue->arr[i]);
    printf("%d\n", queue->arr[i]);
}

void destroyQueue(CircularQueue* queue) {
    free(queue->arr);
    free(queue);
}

int main() {
    CircularQueue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    display(queue);

    printf("Dequeued element: %d\n", dequeue(queue));
    display(queue);

    enqueue(queue, 50);
    enqueue(queue, 60);
    display(queue);

    destroyQueue(queue);

    return 0;
}
