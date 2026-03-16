class Solution {
private:
    int fn(int i,int k,int end,vector<int>&v,vector<vector<int>>&dp){
        if(k==0||i>end){
            return 0;
        }
        if(dp[i][k]!=-1)return dp[i][k];

        int take=v[i]+fn(i+2,k-1,end,v,dp);
        int nottake=fn(i+1,k,end,v,dp);

        return dp[i][k]= max(take,nottake);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        vector<vector<int>> dp1(n,vector<int>((n/3) + 1,-1));
        int x=fn(0,n/3,n-2,slices,dp1);

        vector<vector<int>> dp2(n,vector<int>((n/3) + 1,-1));
        int y=fn(1,n/3,n-1,slices,dp2);
        return max(x,y);
    }
};