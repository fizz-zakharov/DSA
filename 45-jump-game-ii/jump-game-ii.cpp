class Solution {
private:
    int fn(int i,vector<int>&v,int n,vector<int>&dp){
        if(i>=n)return INT_MAX;
        if(i==n-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int a=INT_MAX;
        for(int j=1;j<=v[i];j++){
            int x=fn(i+j,v,n,dp);
            if(x!=INT_MAX)a=min(a,1+x);
        }
        return dp[i]= a;
    }
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return fn(0,nums,n,dp);
    }
};