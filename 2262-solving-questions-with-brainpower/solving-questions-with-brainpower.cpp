class Solution {
private:
    long long fn(int i,vector<vector<int>>&v,int n,vector<long long>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        //take
        long long a=v[i][0]+fn(i+v[i][1]+1,v,n,dp);

        //skip
        long long b=fn(i+1,v,n,dp);

        return dp[i] = max(a,b);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n,-1);

        return fn(0,questions,n,dp);

    }
};