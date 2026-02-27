// Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
int data;
struct Node* next;
struct Node* prev;
} Node;
Node* head = NULL;
Node* tail = NULL;
void insert(int value) {
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->data = value;
newNode->next = NULL;
newNode->prev = NULL;
if (head == NULL) {
        head = tail = newNode;
} else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void traverse() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main() {
int n;
scanf("%d", &n);
for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insert(value);
}
traverse();
return 0;
}