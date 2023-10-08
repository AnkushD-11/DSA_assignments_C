//Write a program to implement tree traversal.

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

void inorder(node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ->", root->data);
    inorder(root->right);
}

void preorder(node* root){
    if(root==NULL)
        return;
    printf("%d ->", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ->", root->data);
}

node* create(value){
    node* new = (node*)malloc(sizeof(node));
    new->data = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

node* insertleft(node* root, int value)
{
    root->left = create(value);
    return root->left;
}

node* insertright(node* root, int value)
{
    root->right = create(value);
    return root->right;
}

int main(){
    node* root = create(7);
    insertleft(root,4);
    insertright(root,8);
    insertleft(root->left,1);
    insertright(root->right,5);
    insertleft(root->left, 6);
    insertright(root->right, 3);
    printf("Inorder \n");
    inorder(root);
    printf("\nPreorder \n");
    preorder(root);
    printf("\nPostorder \n");
    postorder(root);
}