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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(slow->next!=NULL && fast->next!=NULL && fast->next->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast->next!=NULL){
            prev=slow;
            slow=slow->next;
        }
        if(prev!=NULL){
            if(slow->next!=NULL)prev->next=slow->next;
            else prev->next=NULL;
            slow->next=NULL;
        }
        else return NULL;
        return head;

    }
};