class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Use a stack-allocated dummy node to avoid memory leaks
        ListNode dummy(-1);
        ListNode* temp = &dummy;
        
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        
        // Traverse both lists and append the smaller node
        while (t1 != nullptr && t2 != nullptr) {
            if (t1->val < t2->val) {
                temp->next = t1;
                t1 = t1->next;
            } else {
                temp->next = t2;
                t2 = t2->next;
            }
            temp = temp->next; // Move temp forward
        }
        
        // Attach whichever list has remaining nodes
        if (t1 != nullptr) {
            temp->next = t1;
        } else {
            temp->next = t2;
        }
        
        return dummy.next;
    }
};