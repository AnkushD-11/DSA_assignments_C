// Queue using Array

#include<stdio.h>
#define MAX 5
void enqueue(int data);
void dequeue();
void display();

int items[MAX], front = -1, rear =-1;
int main(){
    dequeue();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    display();
    dequeue();
    dequeue();
    dequeue();
    display();

}

void enqueue(int value){
    if(rear==MAX-1)
        printf("\nQueue is full");
    else{
        if(front==-1)
            front=0;
        rear++;
        items[rear]=value;
        printf("Inserting-> %d", value);
    }
}

void dequeue(){
    if(front==-1){
        printf("\nQueue is empty");
    }
    else{
        printf("\n Deleting %d", items[front]);
    }
    front++;
    if(front>=rear)
        front=rear=-1;
}

void display(){
    if(rear==-1)
        printf("Queue is empty");
    else{
        int i;
        printf("\n Queue elements are: \n");
        for(i=front; i<=rear; i++)
            printf("%d->", items[i]);
    }
    printf("MAX");
    printf("\n");
}
