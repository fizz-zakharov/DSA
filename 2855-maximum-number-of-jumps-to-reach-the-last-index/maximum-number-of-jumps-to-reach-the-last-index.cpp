class Solution {
private:
    long long fn(int i,int j,vector<int>&v,int k,vector<vector<long long>>&dp){
        if(i<0||j<0)return -1e10;
        if(j==0){
            if(abs(v[i]-v[j])<=k)return 1;
        }
        if(dp[i][j]!=-1)return dp[i][j];

        long long a=-1e10;
        if(abs(v[i]-v[j])<=k)a=1+fn(j,j-1,v,k,dp);
        long long b=fn(i,j-1,v,k,dp);

        return dp[i][j]=max(a,b);
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<long long>> dp(n,vector<long long>(n,-1));
        long long ans=fn(n-1,n-2,nums,target,dp);
        return (ans<0)?-1:ans;
    }
};