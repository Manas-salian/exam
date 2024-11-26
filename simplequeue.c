#include<stdio.h>
#define SIZE 5

int q[SIZE];
int front = -1,rear = -1;

void enqueue(int item){
    if(rear==SIZE-1){
        printf("Overflow\n");
    }
    else{
        if (rear==-1 && front==-1){  // to see if this is the first item being added
            rear = 0;
            front = 0;
            q[rear]=item;
        }
        else{
            rear +=1;
            q[rear]=item;
        }
        printf("item inserted\n");
    }
}

void dequeue(){
    int item;
    if(front==-1){
        printf("Underflow\n");
    }
    else{
        item =q[front];
        if(front==rear){
            front = -1;
            rear = -1;
        } 
        else{
            front+=1;
        }
        printf("Item deleted\n");
    }
}

void display(){
    if(rear==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue elements are:\n");
        for(int i=front;i<=rear;i++){
            printf("%d\t",q[i]);
        }
        printf("\n");
    }
}

void main(){
    display();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
}