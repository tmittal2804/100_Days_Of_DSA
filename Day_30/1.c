// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct ListNode* temp = head;
    int length = 1;

    // Step 1: Find length
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Step 2: Make circular
    temp->next = head;

    // Step 3: Reduce k
    k = k % length;
    
    int stepsToNewHead = length - k;

    struct ListNode* newTail = head;

    // Step 4: Find new tail
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    struct ListNode* newHead = newTail->next;

    // Step 5: Break circle
    newTail->next = NULL;

    return newHead;
}

// Helper function to print list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Example main
int main() {
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int k = 2;

    printf("Original List: ");
    printList(head);

    head = rotateRight(head, k);

    printf("Rotated List: ");
    printList(head);

    return 0;
}