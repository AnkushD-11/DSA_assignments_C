//Insertion and Deletion at different position in Doubly circular LL

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        struct Node* last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        (*head)->prev = newNode;
        last->next = newNode;
        *head = newNode;
    }
}

// Function to insert a new node at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        printf("List is empty. Cannot insert at specified position.\n");
        return;
    }

    if (position == 0) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* current = *head;
    int i = 0;
    while (i < position - 1) {
        current = current->next;
        i++;
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

// Function to delete a node at a specific position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }

    struct Node* temp = *head;

    if (position == 0) {
        struct Node* last = (*head)->prev;

        if (*head == last) {
            free(*head);
            *head = NULL;
        } else {
            last->next = (*head)->next;
            (*head)->next->prev = last;
            free(*head);
            *head = last->next;
        }

        return;
    }

    int i = 0;
    while (i < position) {
        temp = temp->next;
        i++;
    }

    if (temp == *head) {
        printf("Invalid position. Cannot delete at specified position.\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

// Function to display the circular doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Circular Doubly Linked List is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main() {
    struct Node* head = NULL;

    //insertAtEnd(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head,40);

    displayList(head);

    insertAtPosition(&head, 50, 1);
    displayList(head);

    deleteAtPosition(&head, 2);
    displayList(head);

    return 0;
}
