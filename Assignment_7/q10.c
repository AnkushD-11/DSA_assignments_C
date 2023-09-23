// Generate binary numbers from 1 to n using queue

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for a queue node
typedef struct {
    int data;
} QueueNode;

// Structure for a queue
typedef struct {
    QueueNode* arr[MAX_SIZE];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(Queue* queue) {
    return (queue->front == -1);
}

void enqueue(Queue* queue, int data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;

    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        exit(1);
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear++;
    }

    queue->arr[queue->rear] = newNode;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        exit(1);
    }

    QueueNode* node = queue->arr[queue->front];
    int data = node->data;

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }

    free(node);
    return data;
}

void generateBinaryNumbers(int n) {
    Queue* queue = createQueue();
    
    // Start from 1
    enqueue(queue, 1);
    
    for (int i = 0; i < n; i++) {
        int front = dequeue(queue);
        printf("%d\n", front);
        
        // Append '0' and '1' to the front and enqueue them
        enqueue(queue, front * 10);
        enqueue(queue, front * 10 + 1);
    }
    
    free(queue);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Binary numbers from 1 to %d:\n", n);
    generateBinaryNumbers(n);

    return 0;
}
