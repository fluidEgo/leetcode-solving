/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        //find the mid
        ListNode* mid=middleNode(head);
        ListNode* hs=reverseList(mid);
        ListNode* hf=head;

        while (hs->next!=nullptr){
            ListNode* nextHf=hf->next;
            ListNode* nextHs=hs-> next;

            hf->next=hs;
            hs->next=nextHf;

            hf=nextHf;
            hs=nextHs;
        }
    }
    private:
        ListNode* middleNode(ListNode* head){
            ListNode* s= head;
            ListNode* f=head;

            while(f!=nullptr && f->next!=nullptr){
                s=s->next;
                f=f->next->next;
            }
            return s;
        }
        ListNode* reverseList(ListNode* head){
            ListNode* prev=nullptr;
            ListNode* curr=head;

            while(curr!=nullptr){
                ListNode* nextNode=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nextNode;
            }

            return prev;
        }
};
