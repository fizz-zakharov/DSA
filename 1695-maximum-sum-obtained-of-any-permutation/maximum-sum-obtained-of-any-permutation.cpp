class Solution {
long long MOD=1e9+7;
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();
        vector<int> diff(n+1,0);
        for(auto it:requests){
            int l=it[0];
            int r=it[1];
            diff[l]++;
            diff[r+1]--;
        }
        sort(nums.begin(),nums.end());
        vector<int> pre(n);
        int sum=0;
        for(int i=0;i<n;i++){
            sum=(sum+diff[i])%MOD;
            pre[i]=sum;
        }
        vector<int> v;
        for(int i=0;i<n;i++){
            if(pre[i])v.push_back(pre[i]);
        }
        sort(v.begin(),v.end());
        int ans=0;
        int ind=n-1;
        for(int i=v.size()-1;i>=0;i--){
            ans=(ans+(long long)nums[ind]*v[i])%MOD;
            ind--;
        }
        return ans;
    }
};