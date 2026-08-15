class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n=barcodes.size();
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[barcodes[i]]++;
        }
        for(auto it:m){
            pq.push({it.second,it.first});
        }
        vector<int> ans(n);
        int ind=0;
        while(!pq.empty()){
            int f=pq.top().first;
            int el=pq.top().second;
            pq.pop();
            while(f--){
                ans[ind]=el;
                ind+=2;
                if(ind>=n){
                    ind=1;
                }
            }
        }
        return ans;
    }
};