#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int coeff;
    int pow;
    struct node *next;
}Node;

Node * createPoly(int n){
    int coeff, pow;
    Node *h, *nw, *last;
    int choice;
    h = NULL;
    for(int i=0;i<n;i++){
        printf("Enter Coefficient: ");
        scanf("%d",&coeff);
        printf("Enter Power: ");
        scanf("%d",&pow);
        nw = (Node*)malloc(sizeof(Node));
        nw->coeff = coeff;
        nw->pow = pow;
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

void displayPoly(Node *h){
    printf("\nPolynomial: ");
    while(h!=NULL){
        printf("%dx^%d  ", h->coeff, h->pow);
        h=h->next;
    }
    printf("\n");
}

void polyadd(Node* poly1, Node* poly2, Node* poly)
{
    while (poly1!=NULL&&poly2!=NULL) {
        poly->next=(Node*)malloc(sizeof(Node));
        poly = poly->next;
        poly->next = NULL;
        if (poly1->pow > poly2->pow) {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        } else {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1!=NULL|| poly2!=NULL) {
        if (poly1->next) {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2->next) {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly->next = (Node*)malloc(sizeof(Node));
        poly = poly->next;
        poly->next = NULL;
    }
}

void main(){
    Node * poly1 = NULL, * poly2 = NULL, * poly3 = NULL;
    int n1, n2;
    printf("Enter size of first polynomial: ");
    scanf("%d",&n1);
    printf("Enter details of first polynomial:\n");
    poly1 = createPoly(n1);
    printf("Enter size of second polynomial: ");
    scanf("%d",&n2);
    printf("Enter details of second polynomial:\n");
    poly2 = createPoly(n2);
    displayPoly(poly1);
    displayPoly(poly2);
    
    poly3 = (Node*)malloc(sizeof(Node));
    polyadd(poly1, poly2, poly3);
    
    displayPoly(poly3->next);
}