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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        map<ListNode*,ListNode*> m;
        ListNode* temp=head;
        int c=0;
        m[head]=NULL;
        int lcp=-1;
        ListNode* t;
        int mn=INT_MAX;
        bool ch=true;
        int start=-1;
        while(temp){
            if(c==1){
                t=head;
                m[temp]=t;
                t=t->next;
                
                if(temp->next!=NULL){
                    if((m[temp]->val<temp->val && temp->next->val<temp->val)||(m[temp]->val>temp->val && temp->next->val>temp->val)){
                        if(lcp!=-1)mn=min(mn,abs(c-lcp));
                        lcp=c;
                        if(ch){
                            start=c;
                            ch=false;
                        }
                    }
                }
            }
            if(c>1){
                m[temp]=t;
                t=t->next;
                if(temp->next!=NULL){
                    if((m[temp]->val<temp->val && temp->next->val<temp->val)||(m[temp]->val>temp->val && temp->next->val>temp->val)){
                        if(lcp!=-1)mn=min(mn,abs(c-lcp));
                        lcp=c;
                        if(ch){
                            start=c;
                            ch=false;
                        }
                    }
                }
            }
            c++;
            temp=temp->next;
        }
        if(mn==INT_MAX)return {-1,-1};
        return {mn,lcp-start};
    }
};