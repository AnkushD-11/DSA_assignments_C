// Create a binary tree using C

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int key;
    struct node* left, *right;
}node;

node* create(int val){
    node* new = (node*)malloc(sizeof(node));
    new->key = val;
    new->left = NULL;
    new->right = NULL;
    return new;
}

node* treeinsert(node* root, int val)
{
    if(root==NULL)
        return create(val);
    
    if(root->key < val)
        root->right = treeinsert(root->right,val);
    else if(root->key > val)
        root->left = treeinsert(root->left, val);
    return root;
}

void insertorder(node* root)
{
    if(root== NULL)
        return;
    insertorder(root->left);
    printf("%d ",root->key);
    insertorder(root->right);
    
}

int main(){
    node* root = NULL;
    root = treeinsert(root,7);
    root = treeinsert(root,4);
    root = treeinsert(root,8);
    root = treeinsert(root,1);
    root = treeinsert(root,5);
    root = treeinsert(root,2);
    root = treeinsert(root,9);
    root = treeinsert(root,3);
    
    insertorder(root);
}