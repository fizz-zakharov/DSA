class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n);
        vector<int> suff(n);
        int mx=INT_MIN;
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            pre[i]=mx;
            mn=min(mn,nums[n-1-i]);
            suff[n-1-i]=mn;
        }
        for(int i=0;i<n;i++){
            if(pre[i]-suff[i]<=k)return i;
        }
        return -1;
    }
};