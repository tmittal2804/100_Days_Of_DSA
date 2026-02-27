/*Given the head of a singly linked list, the task is to remove a cycle if present.
 A cycle exists when a node's next pointer points back to a previous node, forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, it will print false.
 /*

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
struct Node {
    int data;
    Node* next;
};
*/

class Solution {
public:
    void removeLoop(Node* head) {
        
        if (!head || !head->next)
            return;

        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect Loop
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                
                // Step 2: Find starting point of loop
                slow = head;

                // Special case: loop starts at head
                if (slow == fast) {
                    while (fast->next != slow)
                        fast = fast->next;
                } 
                else {
                    while (slow->next != fast->next) {
                        slow = slow->next;
                        fast = fast->next;
                    }
                }

                // Step 3: Break the loop
                fast->next = NULL;
                return;
            }
        }
    }
};