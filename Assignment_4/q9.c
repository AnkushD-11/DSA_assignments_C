// Detect a loop in a list

#include <stdio.h>
#include <stdbool.h>

// Define the structure for a linked list node
typedef struct Node {
    int val;
    struct Node *next;
}NODE;

// Function to detect a loop in a linked list
bool hasCycle(NODE *head) {
    NODE *p = head;
    NODE *q = head;

    while (q != NULL && q->next != NULL) {
        p = p->next;
        q = q->next->next;

        if (p == q) {
            return true; // Loop detected
        }
    }

    return false; // No loop detected
}

int main() {
    // Example linked list with a loop
    NODE node1, node2, node3, node4, node5;
    
    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    node4.val = 4;
    node5.val = 5;
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node2; // Creating a loop

    bool has_loop = hasCycle(&node1);
    printf(has_loop ? "The linked list has a loop.\n" : "The linked list does not have a loop.\n");

    return 0;
}
