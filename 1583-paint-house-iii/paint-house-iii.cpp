class Solution {
private:
    int fn(int i,int k,int lastcolor,vector<int>&v,vector<vector<int>>&c,int m,int n,int target,vector<vector<vector<int>>>&dp){
        if(i>=m){
            if(k==target)return 0;
            return 1e9;
        }
        if(k>target)return 1e9;
        if(dp[i][k][lastcolor]!=-1)return dp[i][k][lastcolor];
        if(v[i]!=0){
            if(lastcolor==v[i])return dp[i][k][lastcolor]= fn(i+1,k,lastcolor,v,c,m,n,target,dp);
            else return dp[i][k][lastcolor]= fn(i+1,k+1,v[i],v,c,m,n,target,dp);
        }
        int a=1e9;
        for(int j=0;j<n;j++){
            if(j+1==lastcolor)a=min(a,c[i][j]+fn(i+1,k,lastcolor,v,c,m,n,target,dp));
            else a=min(a,c[i][j]+fn(i+1,k+1,j+1,v,c,m,n,target,dp));
        }
        return dp[i][k][lastcolor] = a;

    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(target+1,vector<int>(n+1,-1)));
        int ans=fn(0,0,0,houses,cost,m,n,target,dp);
        return (ans>=1e9)?-1:ans;
    }
};