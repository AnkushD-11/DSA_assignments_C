#include <stdio.h>
#include <stdlib.h>
  
typedef struct node{
    int item;
    struct node *next;
}Node;
  
Node * createList() {
    Node *h, *nw, *last;
    h = NULL;
    int n;
    printf("Enter size of the linked list: ");
    scanf("%d",&n);
    printf("Enter node data:\n");
    for(int i=0;i<n;i++){
        nw = (Node*)malloc(sizeof(Node));
        scanf("%d",&nw->item);
        nw->next = NULL;
        if(h==NULL)
            h = last = nw;
        else{
            last->next = nw;
            last = nw;
        }
    }
    return h;
}

void displayList(Node *h){
    printf("\nhead-->");
    while(h!=NULL){
        printf("%d-->",h->item);
        h=h->next;
    }
    printf("NULL\n\n");
}

void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void pairWiseSwap(Node* head){
    Node* temp = head;
 
    while (temp != NULL && temp->next != NULL) {
        swap(&temp->item, &temp->next->item);
        temp = temp->next->next;
    }
}

void main(){
    Node * head = NULL;
    head = createList();
    printf("\nLinked list");
    displayList(head);
    pairWiseSwap(head);
    displayList(head);
}