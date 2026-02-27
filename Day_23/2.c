/*Given head, the head of a linked list, determine if the linked list has a cycle in it. There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.
*/

bool hasCycle(struct ListNode *head) {
    
    if (head == NULL || head->next == NULL)
        return false;
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;              // move 1 step
        fast = fast->next->next;        // move 2 steps
        
        if (slow == fast) {
            return true;                // cycle detected
        }
    }
    
    return false;                       // no cycle
}