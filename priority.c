// logic is just append new item to end of queue and the sort it based on priority
/*
typedef struct{
    int value;
    int priority;
}item;
*/

#include <stdio.h>
#define SIZE 5

struct Item{            // structure Item
    int value;
    int priority;
};

typedef struct Item item;       // defining strct Item as a type item for ease of access,

item queue[SIZE]; //array of objects
int i = -1;       // counter

void insert(int val, int pry) {
    if (i == SIZE - 1) {
        printf("Overflow\n");
        return;
    }

    i++;          //increment to show increase in no of items
    queue[i].value = val;
    queue[i].priority = pry;

    item temp;      // sorting
    for (int j = i; j > 0; j--) {  // from last element to 0th element, linear sort
        if (queue[j].priority < queue[j - 1].priority) {
            temp = queue[j];
            queue[j] = queue[j - 1];
            queue[j - 1] = temp;
        }else {
            break;
        }
    }
    printf("Item inserted: %d - {%d}\n", val, pry);
}

void delete() {
    if (i == -1) {
        printf("Underflow\n");
        return;
    }
    
    int item = queue[i].value;
    i--;
    printf("Item deleted: %d\n", item);
}

void display() {
    if (i == -1) {
        printf("Queue is empty\n");
        return;
    }

    for (int j = 0; j <= i; j++) {          // displays all items from 0th idex to the total count of items present
        printf("%d - {%d}\n", queue[j].value, queue[j].priority);
    }
}

int main() {
    insert(10, 5);
    insert(20,10);
    insert(30,7);
    insert(15,3);
    insert(12,30);
    insert(17,20);
    display();
    delete();
    delete();
    delete();
    delete();
    delete();
    delete();
    display();
    return 0;
}
