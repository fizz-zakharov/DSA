class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<n;i++)v.push_back({nums1[i],{nums2[i],i}});
        sort(v.begin(),v.end());
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        long long sum=0;
        vector<long long> ans(n,0);
        for(int i=0;i<n;i++){
            if(i>0 && v[i].first==v[i-1].first){
                ans[v[i].second.second]=ans[v[i-1].second.second];
            } 
            else ans[v[i].second.second]=sum;
            if(pq.size()<k){
                pq.push(v[i].second.first);
                sum+=v[i].second.first;
            }
            else{
                if(v[i].second.first<=pq.top()){
                    continue;
                }
                else{
                    sum-=pq.top();
                    sum+=v[i].second.first;
                    pq.pop();
                    pq.push(v[i].second.first);
                }
            }
        }
        return ans;
    }
};