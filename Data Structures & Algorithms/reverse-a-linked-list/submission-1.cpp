class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case: if list is empty or has only one node
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        // Dive to the end of the list
        ListNode* newHead = reverseList(head->next);
        
        // Define 'front' as the next node
        ListNode* front = head->next;
        
        // Reverse the arrow
        front->next = head;
        
        // Sever the old forward connection to prevent cycles
        head->next = NULL;
        
        return newHead;
    }
};