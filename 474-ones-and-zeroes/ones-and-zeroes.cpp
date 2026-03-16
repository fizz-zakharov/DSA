class Solution {
private:
    int fn(int i,int m,int n,vector<string>&v,vector<vector<vector<int>>>&dp){
        if(i>=v.size())return 0;
        if(dp[i][m][n]!=-1)return dp[i][m][n];

        string s=v[i];
        int o=0,z=0;
        for(int j=0;j<s.size();j++){
            if(s[j]=='1')o++;
            else z++;
        }
        int ans=0;
        if(m-z>=0 && n-o>=0)ans=1+fn(i+1,m-z,n-o,v,dp);
        ans=max(ans,fn(i+1,m,n,v,dp));

        return dp[i][m][n]= ans;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz=strs.size();
        vector<vector<vector<int>>> dp(sz,vector<vector<int>>(m+1,vector<int>(n+1,-1)));        

        return fn(0,m,n,strs,dp);
    }
};