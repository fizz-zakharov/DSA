class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0)return false;
        map<int,int> m;
        for(int i=0;i<n;i++)m[nums[i]]++;
        priority_queue<pair<int,int>> pq;
        for(auto it:m){
            pq.push({it.first,it.second});
        }
        int kk=n/k; //kk groups and we want each group to have k consecutive cards
        while(kk--){
            int temp=k;
            vector<pair<int,int>> rem;
            int prev=-1;
            while(temp--){
                int num=pq.top().first;
                int freq=pq.top().second;
                if(freq>1)rem.push_back({num,freq-1});
                pq.pop();
                if(prev!=-1 && num+1!=prev)return false;
                prev=num;
            }
            for(int i=0;i<rem.size();i++)pq.push(rem[i]);
        }
        return true;
    }
};