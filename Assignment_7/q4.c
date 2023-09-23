// Implement multiple queues in single arrays.

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUES 5
#define MAX_SIZE 10

typedef struct {
    int* arr;
    int front;
    int rear;
    int size;
} CircularQueue;

typedef struct {
    CircularQueue** queues;
} MultiQueue;

MultiQueue* createMultiQueue() {
    MultiQueue* mq = (MultiQueue*)malloc(sizeof(MultiQueue));
    mq->queues = (CircularQueue**)malloc(MAX_QUEUES * sizeof(CircularQueue*));
    
    for (int i = 0; i < MAX_QUEUES; i++) {
        mq->queues[i] = (CircularQueue*)malloc(sizeof(CircularQueue));
        mq->queues[i]->arr = (int*)malloc(MAX_SIZE * sizeof(int));
        mq->queues[i]->front = -1;
        mq->queues[i]->rear = -1;
        mq->queues[i]->size = MAX_SIZE;
    }

    return mq;
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

void destroyMultiQueue(MultiQueue* mq) {
    for (int i = 0; i < MAX_QUEUES; i++) {
        free(mq->queues[i]->arr);
        free(mq->queues[i]);
    }
    free(mq->queues);
    free(mq);
}

int main() {
    MultiQueue* mq = createMultiQueue();

    for (int i = 0; i < MAX_QUEUES; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            enqueue(mq->queues[i], (i + 1) * 100 + (j + 1));
        }
    }

    for (int i = 0; i < MAX_QUEUES; i++) {
        printf("Queue %d:\n", i + 1);
        display(mq->queues[i]);
    }
    for (int i = 0; i < MAX_QUEUES; i++) {
        for (int j = 0; j < MAX_SIZE / 2; j++) {
            dequeue(mq->queues[i]);
        }
    }

    for (int i = 0; i < MAX_QUEUES; i++) {
        printf("Updated Queue %d:\n", i + 1);
        display(mq->queues[i]);
    }

    destroyMultiQueue(mq);

    return 0;
}
