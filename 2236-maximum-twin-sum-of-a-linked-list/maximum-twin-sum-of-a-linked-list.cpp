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
    int pairSum(ListNode* head) {
        int sum=0;
        int len=0;
        ListNode* tail=head;
        unordered_map<ListNode*,ListNode*> par;
        while(tail->next!=NULL){
            len++;
            par[tail->next]=tail;
            tail=tail->next;
        }
        len++;
        ListNode* temp=head;
        for(int i=0;i<=(len/2)-1;i++){
            sum=max(sum,temp->val+tail->val);
            temp=temp->next;
            tail=par[tail];
        }
        return sum;
    }
};