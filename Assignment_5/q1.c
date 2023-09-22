// Single circular LL

#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
    int data;
    struct NODE *next;
}node;

node *head , *tail = NULL;

void create_node(int data)
{
    node* new = (node*)malloc(sizeof(node));
    new->data = data;

    if(head == NULL)
    {
        head = new;
        tail = new;
        new->next = head;
    }

    else
        tail->next = new;
        tail = new;
        tail->next = head;
}

void display()
{
    node *current = head;
    if(head == NULL)
    {
        printf("List is empty");
        return;
    }
    else{
        printf("Nodes of Circular LL are:\n");
        do{
            printf("%d->", current->data);
            current = current->next;
        }while(current!=head);
    
    printf("\n");
}
}

int main(){
    create_node(1);
    create_node(2);
    create_node(3);
    create_node(4);
    display();
}
