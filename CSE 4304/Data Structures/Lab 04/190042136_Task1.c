#include<stdio.h>

#define MAXSIZE 6
#define true 1
#define false 0

int itemcount = 0;
int front = 0;
int rear = -1;

int isFull() {
    if (itemcount == MAXSIZE )
        return true;

    return false;
}

int isEmpty() {
    if (itemcount == 0)
        return true;
    return false;
}

int peek(int* que) {
    if (itemcount)
        return que[front];
}

void enque(int* que, int data) { // Do not forget to update the value of itemcount
    if (!isFull()) {//Check if queue is not full
        if (rear == MAXSIZE - 1) {
            rear = -1;
        }//Check for the critical case
         //increment the value of rear and insert the value
        rear++;
        que[rear] = data;
        itemcount++;
    }

    else
        printf("\nCan't push value, queue is full\n");

}

int deque(int* que) { //Do not forget to update the value of itemcount
    int data;
    if (!isEmpty()) { //Check if the queue is not empty
        // Save the data from the front index
        data = que[front];
        front++;// increment the front and check for critical case
        itemcount--;
        if (front == MAXSIZE - 1 ) {
            front = 0;
        }
        // return the saved value
        return data;
    }
    else
        printf("\nCan't pop value, queue is empty\n");
}

void display(int* que) {
    // Display all the content of the que
    // Front value is diplayed first, then rest of the values are displayed upto rear.
    // Consider the critical cases as well.

    if (!isEmpty()) {
        if (rear > front) {
            for (int i = front; i <= rear; i++) {
                printf("%d\n", que[i]);

            }
        }
    else if (front > rear) {
        for (int i = front; i < MAXSIZE; i++) {
            printf("%d\n", que[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d\n", que[i]);
        }

        }
}
    else {
        printf("Queue is empty\n");
    }
}

int main() {
    int x;
    int que[MAXSIZE];
    enque(que, 5);
    enque(que, 6);
    enque(que, 7);
    enque(que, 8);
    enque(que, 9);
    enque(que, 10);
    enque(que, 11);
    display(que);
    deque(que);
    enque(que, 12);
    display(que);

    return 0;
}
