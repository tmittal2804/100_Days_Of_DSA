// Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
int countKey(struct Node* head, int key) {
int count = 0;
struct Node* current = head;
while (current != NULL) {
if (current->data == key) {
count++;
    }
current = current->next;
    }
return count;
}
int main() {
int n, key, val;
struct Node *head = NULL, *tail = NULL;
if (scanf("%d", &n) != 1) return 0;
for (int i = 0; i < n; i++) {
scanf("%d", &val);
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = val;
newNode->next = NULL;
if (head == NULL) {
    head = newNode;
    tail = newNode;
} else {
    tail->next = newNode;
    tail = newNode;
    }
}
scanf("%d", &key);
printf("%d\n", countKey(head, key));
struct Node* temp;
while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
}
return 0;
}