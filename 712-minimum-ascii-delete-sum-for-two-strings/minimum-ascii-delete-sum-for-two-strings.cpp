class Solution {
private:
    int fn(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i<0||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        int a=0;
        if(s1[i]==s2[j])a=2*s1[i]+fn(i-1,j-1,s1,s2,dp);
        int b=fn(i-1,j,s1,s2,dp);
        int c=fn(i,j-1,s1,s2,dp);
        return dp[i][j]= max({a,b,c});
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        int total=0;
        for(int i=0;i<n;i++)total+=s1[i];
        for(int i=0;i<m;i++)total+=s2[i];
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return total - fn(n-1,m-1,s1,s2,dp);
    }
};