class Solution {
private:
    int fn(int i,int j,string& s,vector<vector<int>>&dp){
        if(i==j)return 1;
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int k=i;
        while(k<=j && s[k]==s[i]){
            k++;
        }
        int a=1+fn(k,j,s,dp);
        int b=INT_MAX;
        for(int x=k+1;x<=j;x++){
            if(s[x]==s[i])b=min(b,fn(k,x-1,s,dp)+fn(x,j,s,dp));
        }
        return dp[i][j] = min(a,b);
    }
public:
    int strangePrinter(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fn(0,n-1,s,dp);
    }
};