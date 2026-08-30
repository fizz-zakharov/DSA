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
private:
    void swapnodes(ListNode* a,ListNode* b){
        swap(a->val,b->val);
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)return head;
        ListNode* leftnode;
        ListNode* rightnode;
        ListNode* temp=head;
        map<ListNode*,ListNode*> m;
        ListNode* preva=NULL;
        ListNode* prevb=NULL;
        int l=left;
        int r=right;
        int c=0;
        while(left--){
            leftnode=temp;
            temp=temp->next;
            if(c==0){
                c++;
                continue;
            }
            if(c==1){
                preva=head;
            }
            else{
                preva=preva->next;
            }
            c++;
        }
        c=0;
        temp=head;
        m[head]=NULL;
        while(right--){
            rightnode=temp;
            temp=temp->next;
            if(c==0){
                c++;
                continue;
            }
            if(c==1){
                prevb=head;
            }
            else{
                prevb=prevb->next;
            }
            m[rightnode]=prevb;
            c++;
        }
        while(l<r){
            swapnodes(leftnode,rightnode);
            leftnode=leftnode->next;
            rightnode=m[rightnode];
            l++;
            r--;
        }
        return head;
    }
};