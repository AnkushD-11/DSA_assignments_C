// Write a program to perform insertion & deletion of element in a given list.

#include <stdio.h>
#include <stdlib.h>

// Structure for the linked list node
struct Node {
    int data;
    struct Node* next;
};

/* Given a reference (pointer to pointer) to the head of a
   list and an int, inserts a new node on the front of the
   list. */

void insert(struct Node** head, int new)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new;
    new_node->next = (*head);
    (*head) = new_node;
}

void delete(struct Node** head, int key)
{
    struct Node *temp = *head, *prev;
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Changed head
        free(temp); // free old head
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;
    
    prev->next = temp->next;
 
    free(temp); // Free memory
}

void printList(struct Node* node)
{
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    insert(&head, 7);
    insert(&head, 1);
    insert(&head, 3);
    insert(&head, 2);
 
    puts("Created Linked List: ");
    printList(head);
    delete(&head, 1);
    puts("\nLinked List after Deletion of 1: ");
    printList(head);
    return 0;
}
 
