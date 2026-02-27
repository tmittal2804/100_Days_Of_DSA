// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

/* Function to find intersection node */
struct Node* getIntersectionNode(struct Node* headA, struct Node* headB) {
    
    if (headA == NULL || headB == NULL)
        return NULL;

    struct Node* p1 = headA;
    struct Node* p2 = headB;

    while (p1 != p2) {
        p1 = (p1 == NULL) ? headB : p1->next;
        p2 = (p2 == NULL) ? headA : p2->next;
    }

    return p1;   // either intersection node or NULL
}

/* Utility function to create new node */
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Driver Code */
int main() {
    
    // Common part
    struct Node* common = createNode(8);
    common->next = createNode(10);

    // List A: 3 -> 6 -> 9 -> 8 -> 10
    struct Node* headA = createNode(3);
    headA->next = createNode(6);
    headA->next->next = createNode(9);
    headA->next->next->next = common;

    // List B: 4 -> 8 -> 10
    struct Node* headB = createNode(4);
    headB->next = common;

    struct Node* intersection = getIntersectionNode(headA, headB);

    if (intersection)
        printf("Intersection at node with value: %d\n", intersection->data);
    else
        printf("No intersection\n");

    return 0;
}