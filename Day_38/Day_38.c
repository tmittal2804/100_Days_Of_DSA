#include <stdio.h>
#define MAX 100
int deque[MAX];
int front = -1, rear = -1;
int isEmpty() {
    return (front == -1);
}
int isFull() {
    return (rear == MAX - 1);
}

void push_front(int x) {
    if(front == 0) {
        printf("Overflow\n");
        return;
    }

    if(isEmpty()) {
        front = rear = 0;
    }
    else {
        front--;
    }

    deque[front] = x;
}

void push_back(int x) {
    if(isFull()) {
        printf("Overflow\n");
        return;
    }

    if(isEmpty()) {
        front = rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = x;
}

void pop_front() {
    if(isEmpty()) {
        printf("Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[front]);

    if(front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back() {
    if(isEmpty()) {
        printf("Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[rear]);

    if(front == rear)
        front = rear = -1;
    else
        rear--;
}

void display() {
    if(isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    for(int i = front; i <= rear; i++)
        printf("%d ", deque[i]);

    printf("\n");
}
int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    push_front(2);
    display();
    pop_front();
    pop_back();
    display();
    return 0;
}