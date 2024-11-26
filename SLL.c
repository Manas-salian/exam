#include<stdio.h>
#include<stdlib.h>

struct node         // creating a node structure
{
    int data;
    struct node *next;
};
typedef struct node NODE;    // defining struct node as a new type NODE for ease of access

NODE *head;

void insert_begin(int item){
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    if(ptr==NULL){
        printf("Overflow\n");
    }
    else{
        if(head==NULL){
            head = ptr;
            ptr->data=item;
            ptr->next=NULL;
        }
        else{
            ptr->data=item;
            ptr->next=head;
            head=ptr;
        }
        printf("Node inserted\n");
    }
}

void insert_end(int item){
    NODE *temp;
    NODE *ptr=(NODE *)malloc(sizeof(NODE));
    if(ptr==NULL){
        printf("Overflow\n");
    }
    else{
        if(head==NULL){
            head=ptr;
            ptr->data=item;
            ptr->next=NULL;
        }
        else{
            temp = head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next = ptr;
            ptr->data=item;
            ptr->next=NULL;
        }
        printf("Node Inserted\n");
    }

}

void delete_begin(){
    NODE *temp;
    if(head==NULL){
        printf("List empty\n");
    }
    else{
        if(head->next==NULL){
            free(head);
            head=NULL;
        }
        else{
            temp=head;
            head=temp->next;
            free(temp);
            printf("Node deleted from beginning\n");
        }
    }
}


void delete_last(){
    NODE *temp;
    if(head==NULL){
        printf("Underflow\n");
    }
    else{
        if(head->next==NULL){
            free(head);
            head==NULL;
        }
        else{
            temp=head;
            while(temp->next->next!=NULL){  //simplify by using temp2 which
                temp=temp->next;            //will be behind temp temp2=temp; and temp=temp->next inside while
            }
            free(temp->next);
            temp->next=NULL;
        printf("Node deleted from end\n");
        }
    }
}

void insert_specific(int item,int loc){
    NODE *temp;
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    if(ptr==NULL){
        printf("Overflow\n");
    }
    else{
        temp=head;
        for(int i=0;i<loc;i++){  
            temp = temp->next;  
            if(temp == NULL){  
                printf("can't insert\n");  
                return;  
            }
        }
        ptr->data=item;
        ptr->next = temp->next;   
        temp->next = ptr;   
        printf("Node inserted\n");  
    }
    
}

void delete_specific(int loc){
    NODE *temp,*temp2;
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        temp = head;
        for(int i=0;i<loc;i++){
            temp2=temp;
            temp=temp->next;
            if(temp==NULL){
                printf("can't delete\n");
                return;
            }
        }
        temp2->next=temp->next;
        free(temp);
        printf("Item deleted\n");
    }
}

void search(int item){
    int loc=0;
    NODE *temp;
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        temp=head;
        while(temp!=NULL){
            if(item==temp->data){
                printf("Item found in location:%d\n",loc);
                return;
            }
            loc++;
            temp = temp->next;
        }
        printf("Item not found\n");
    }
}

void display(){
    NODE *temp;
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        temp=head;
        printf("The list items are:\n");
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main(){
    //put any test cases
    insert_end(10);
    insert_begin(20);
    insert_begin(50);
    insert_end(30);
    insert_end(60);
    display();
    search(60);
    delete_specific(3);
    delete_last();
    insert_specific(35,2);
    display();
}
