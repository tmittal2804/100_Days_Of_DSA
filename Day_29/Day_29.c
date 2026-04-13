#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    struct Node *temp = head;
    int n = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        n++;
    }
    temp->next = head;
    k = k % n;
    int steps = n - k;
    temp = head;
    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;

    return head;
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}
int main() {
int n, k, data;
struct Node *head = NULL, *tail = NULL;
scanf("%d", &n);
for (int i = 0; i < n; i++) {
scanf("%d", &data);
struct Node* newNode = createNode(data);
if (head == NULL) {
    head = newNode;
    tail = newNode;
} else {
    tail->next = newNode;
    tail = newNode;
        }
    }
    scanf("%d", &k);
    head = rotateRight(head, k);
    printList(head);
    return 0;
}