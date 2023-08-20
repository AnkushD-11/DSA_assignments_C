// Linear Linked list

#include<stdio.h>
#include<stdlib.h>

//create node
struct NODE
{
    int data;
    struct NODE *next;
};

void printlinkedlist(struct NODE *p)
{
    while(p != NULL)
    {
        printf("%d--->", p->data);
        p = p->next;
    }
}

int main()
{
    //Initialize nodes
    struct NODE *head;
    struct NODE *one = NULL;
    struct NODE *two = NULL;
    struct NODE *three = NULL;
    struct NODE *four = NULL;
    struct NODE *five = NULL;

    // Memory allocation
    one = (struct NODE*)malloc(sizeof(struct NODE));
    two = (struct NODE*)malloc(sizeof(struct NODE));
    three = (struct NODE*)malloc(sizeof(struct NODE));
    four = (struct NODE*)malloc(sizeof(struct NODE));
    five = (struct NODE*)malloc(sizeof(struct NODE));

    // Assign data data
    one->data = 1;
    two->data = 2;
    three->data = 3;
    four->data = 4;
    five->data = 5;

    // Connect NODEs
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = NULL;

   // printing NODE-data
    head = one;
    printlinkedlist(head);
}

