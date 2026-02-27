//Problem: Count Nodes in Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        struct Node* newNode = malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("%d%c", current->data, current->next ? ' ' : '\n');
        current = current->next;
    }

    return 0;
} 