//Write a program to implement BFS algorithm.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 100

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX_VERTICES];
    bool visited[MAX_VERTICES];
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; ++i) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Function to perform BFS traversal of the graph
void BFS(struct Graph* graph, int startVertex) {
    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = 0, rear = -1;

    // Mark the start vertex as visited and enqueue it
    graph->visited[startVertex] = true;
    queue[++rear] = startVertex;

    printf("Breadth-First Traversal starting from vertex %d: ", startVertex);

    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->data;

            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = true;
                queue[++rear] = adjVertex;
            }

            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    struct Graph* graph = createGraph(7); // Change this to the number of vertices in your graph

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    // Perform BFS starting from vertex 0
    BFS(graph, 0);

    return 0;
}
