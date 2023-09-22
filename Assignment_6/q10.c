// Arrange binary tree with a doubly LL

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct ListNode {
    int data;
    struct ListNode* prev;
    struct ListNode* next;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct ListNode* createListNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void inorderTraversal(struct TreeNode* root, struct ListNode** head, struct ListNode** tail) {
    if (root == NULL)
        return;

    inorderTraversal(root->left, head, tail);

    struct ListNode* newNode = createListNode(root->data);
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }

    inorderTraversal(root->right, head, tail);
}

void displayList(struct ListNode* head) {
    printf("Doubly Linked List: ");
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a sample binary tree
    struct TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    inorderTraversal(root, &head, &tail);

    displayList(head);

    return 0;
}
