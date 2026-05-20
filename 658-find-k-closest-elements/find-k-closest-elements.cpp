class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            if(arr[i]<x)pq.push({x-arr[i],-1});
            if(arr[i]==x)pq.push({0,0});
            if(arr[i]>x)pq.push({arr[i]-x,1});
        }
        vector<int> ans;
        while(k--){
            int diff=pq.top().first;
            int region=pq.top().second;
            pq.pop();
            int el;
            if(region==-1)el=x-diff;
            else el=x+diff;
            
            ans.push_back(el);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }

};