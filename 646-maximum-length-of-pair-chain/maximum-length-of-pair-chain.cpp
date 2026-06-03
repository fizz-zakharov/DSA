class Solution {
private:
    int fn(int i,int prev,int n,vector<vector<int>>&v,vector<vector<int>>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        //take case
        int a=INT_MIN;
        if(prev==-1 || v[prev][1]<v[i][0])a=1+fn(i+1,i,n,v,dp);
        //not take case
        int b=fn(i+1,prev,n,v,dp);
        return dp[i][prev+1] = max(a,b);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return fn(0,-1,n,pairs,dp);
    }
};