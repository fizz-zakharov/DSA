class Solution {
private:
    int fn(int i,int j,vector<int>&v,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(i==j)return v[i];
        if(dp[i][j]!=-1)return dp[i][j];
        int a=v[i]+min(fn(i+2,j,v,dp),fn(i+1,j-1,v,dp));
        int b=v[j]+min(fn(i+1,j-1,v,dp),fn(i,j-2,v,dp));
        return dp[i][j] = max(a,b);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int score=fn(0,n-1,nums,dp);
        return score>=(sum-score);
    }
};