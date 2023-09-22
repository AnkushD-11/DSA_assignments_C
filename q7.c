// Remove a particular character from a Linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, char data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to remove all occurrences of a character from the list
void removeCharacter(struct Node** head, char target) {
    if (*head == NULL) {
        printf("List is empty. Nothing to remove.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* toDelete = NULL;

    while (current != NULL) {
        if (current->data == target) {
            toDelete = current;

            if (current->prev != NULL) {
                current->prev->next = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            if (toDelete == *head) {
                *head = current->next;
            }

            free(toDelete);
        }
        current = current->next;
    }
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%c <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 'A');
    insertAtEnd(&head, 'B');
    insertAtEnd(&head, 'C');
    insertAtEnd(&head, 'B');
    insertAtEnd(&head, 'D');
    insertAtEnd(&head, 'E');
    insertAtEnd(&head, 'B');

    displayList(head);

    char target = 'B';
    removeCharacter(&head, target);

    displayList(head);

    return 0;
}
