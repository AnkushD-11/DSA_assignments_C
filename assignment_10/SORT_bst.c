//Write a program to sort a given set of numbers using BST.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to perform an in-order traversal of the BST
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to sort an array using a BST
void sortArrayWithBST(int arr[], int n) {
    struct Node* root = NULL;

    // Insert elements from the array into the BST
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    // Perform an in-order traversal to get the sorted elements
    inOrderTraversal(root);
}

int main() {
    int arr[] = {12, 4, 5, 6, 9, 2, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Sorted Array: ");
    sortArrayWithBST(arr, n);

    return 0;
}
