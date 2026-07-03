class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({arr[i],i});
        }
        vector<int> ans(n,0);
        int prev=1e9+1;
        int c=1;
        while(!pq.empty()){
            int ind=pq.top().second;
            int cur=pq.top().first;
            pq.pop();
            if(cur==prev){
                ans[ind]=c-1;
                prev=cur;
                continue;
            }
            ans[ind]=c;
            c++;
            prev=cur;
        }
        return ans;
    }
};