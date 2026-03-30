class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // comparator
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (int i = 0; i < n; i++) {
            ListNode* temp = lists[i];
            ListNode* prev = NULL;   
            map<ListNode*, ListNode*> m;

            while (temp) {
                if (prev != NULL) m[temp] = prev;
                prev = temp;
                temp = temp->next;
            }

            for (auto it = m.rbegin(); it != m.rend(); it++) {
                ListNode* cur = it->first;
                ListNode* pr = it->second;
                pr->next = NULL;
                pq.push(cur);
            }
            if (lists[i]) pq.push(lists[i]);
        }

        ListNode* ans = NULL;       
        ListNode* tail = NULL;     

        while (!pq.empty()) {
            if (ans == NULL) {
                ans = pq.top();
                tail = ans;
            } else {
                tail->next = pq.top();
                tail = tail->next;
            }
            pq.pop();
        }

        return ans;
    }
};
