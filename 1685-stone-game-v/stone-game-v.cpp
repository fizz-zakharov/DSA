class Solution {
private:
    int fn(int i,int j,vector<int>&v,vector<vector<int>>&dp){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int r=0;
        for(int k=i;k<=j;k++){
            r+=v[k];
        }
        int l=0;
        int a=INT_MIN,b=INT_MIN,c=INT_MIN;
        for(int k=i;k<j;k++){
            l+=v[k];
            r-=v[k];
            if(l>r)a=max(a,r+fn(k+1,j,v,dp));
            if(r>l)b=max(b,l+fn(i,k,v,dp));
            if(l==r){
                c=max(c,max(r+fn(k+1,j,v,dp),l+fn(i,k,v,dp)));
            }
        }
        return dp[i][j]= max({a,b,c});
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fn(0,n-1,stoneValue,dp);
    }
};