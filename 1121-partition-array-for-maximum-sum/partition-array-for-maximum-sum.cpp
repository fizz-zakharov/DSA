class Solution {
private:
    int fn(int i,int j,int k,vector<int>&v,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int a=0;
        for(int p=i;p<min(i+k,j+1);p++){
            int l=0;
            for(int r=i;r<=p;r++)l=max(l,v[r]);
            int sz=p-i+1;
            a=max(a,l*sz+fn(p+1,j,k,v,dp));
            if(j-p<=k){
                int rs=0;
                for(int r=p+1;r<=j;r++)rs=max(rs,v[r]);
                a=max(a,l*sz+(j-p)*rs);
            }
        }
        return dp[i][j]= a;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fn(0,n-1,k,arr,dp);
    }
};