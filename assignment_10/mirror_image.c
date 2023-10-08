// Write a program to find mirror image of a BST.

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to mirror a binary tree
void mirrorBST(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // Swap the left and right subtrees
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror the left and right subtrees
    mirrorBST(root->left);
    mirrorBST(root->right);
}

// Function to perform an in-order traversal of the tree
void inOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    inOrderTraversal(root->left);

    // Print the value of the current node
    printf("%d ", root->val);

    // Traverse the right subtree
    inOrderTraversal(root->right);
}

int main() {
    // Create a sample BST
    struct TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    printf("Original BST (In-order traversal): ");
    inOrderTraversal(root);
    printf("\n");

    // Mirror the BST
    mirrorBST(root);

    printf("Mirror BST (In-order traversal): ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
