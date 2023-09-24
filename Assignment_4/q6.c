#include <stdio.h>
#include <stdlib.h>
  
typedef struct node{
    int item;
    struct node *next;
}Node;
  
Node * rotate(Node* h, int k) {
    if (k == 0)
        return h;
    Node* current = h;

    int count = 1;
    while (count < k && current != NULL) {
        current = current->next;
        count++;
    }
    if (current == NULL)
        return h;
    Node* kthNode = current;
    while (current->next != NULL)
        current = current->next;
    current->next = h;
    h = kthNode->next;
    kthNode->next = NULL;
    return h;
}
  
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

void main(){
    int k;
    Node * head = NULL;
    head = createList();
    printf("\nLinked list");
    displayList(head);
    printf("Enter k from where to rotate: ");
    scanf("%d",&k);
    head = rotate(head, k);
    printf("\nRotated Linked list");
    displayList(head);
}