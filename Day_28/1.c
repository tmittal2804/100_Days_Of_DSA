/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.
*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int main() {
    int n, i, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    scanf("%d", &n);
    if (n <= 0)
        return 0;
scanf("%d", &value);
head = (struct Node*)malloc(sizeof(struct Node));
head->data = value;
head->next = NULL;
temp = head;
for (i = 1; i < n; i++) {
        scanf("%d", &value);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }
temp->next = head;
temp = head;
do {
    printf("%d ", temp->data);
    temp = temp->next;
} while (temp != head);
return 0;
}