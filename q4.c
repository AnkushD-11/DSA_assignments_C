// Insertions and Deletions in different positions of CLL

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the singly circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode; // Circular reference
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

// Function to insert a new node at a specific position in the list
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    if (position == 1) {
        insertAtBeginning(head, data);
    } else {
        struct Node* temp = *head;
        int i;
        for (i = 1; i < position - 1 && temp->next != *head; i++) {
            temp = temp->next;
        }
        if (i < position - 1) {
            printf("Position out of range.\n");
            free(newNode);
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to delete a node at a specific position in the list
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* temp = *head;
    if (position == 1) {
        while (temp->next != *head) {
            temp = temp->next;
        }
        if (*head == temp) {
            // Only one node in the list
            free(*head);
            *head = NULL;
        } else {
            struct Node* firstNode = *head;
            *head = (*head)->next;
            temp->next = *head;
            free(firstNode);
        }
    } else {
        int i;
        for (i = 1; i < position - 1 && temp->next != *head; i++) {
            temp = temp->next;
        }
        if (i < position - 1 || temp->next == *head) {
            printf("Position out of range.\n");
            return;
        }
        struct Node* deletedNode = temp->next;
        temp->next = deletedNode->next;
        free(deletedNode);
    }
}

// Function to display the singly circular linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    if (head == NULL) {
        printf("Singly Circular Linked List is empty.\n");
        return;
    }
    printf("Singly Circular Linked List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtPosition(&head, 15, 2);
    displayList(head);
    
    deleteAtPosition(&head, 1);
    deleteAtPosition(&head, 2);
    deleteAtPosition(&head, 3);
    displayList(head);
    
    return 0;
}
