// Two way threaded Binary Tree

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    int leftThread;
    int rightThread;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->leftThread = 0;  // 0 indicates left is a child pointer
    newNode->rightThread = 0; // 0 indicates right is a child pointer
    return newNode;
}

// Function to perform in-order traversal using threaded links
void inOrderTraversal(struct TreeNode* root) {
    struct TreeNode* current = root;

    while (current != NULL) {
        while (current->left != NULL && current->leftThread == 0)
            current = current->left;

        printf("%d ", current->data);

        if (current->rightThread)
            current = current->right;
        else {
            current = current->right;
            while (current != NULL && current->leftThread == 1) {
                printf("%d ", current->data);
                current = current->right;
            }
        }
    }
}

// Function to perform reverse in-order traversal using threaded links
void reverseInOrderTraversal(struct TreeNode* root) {
    struct TreeNode* current = root;

    while (current != NULL) {
        while (current->right != NULL && current->rightThread == 0)
            current = current->right;

        printf("%d ", current->data);

        if (current->leftThread)
            current = current->left;
        else {
            current = current->left;
            while (current != NULL && current->rightThread == 1) {
                printf("%d ", current->data);
                current = current->left;
            }
        }
    }
}

int main() {
    struct TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    // Setup threaded links
    root->left->right = root;
    root->right->left = root;

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Reverse in-order traversal: ");
    reverseInOrderTraversal(root);
    printf("\n");

    return 0;
}
