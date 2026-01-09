class Solution {
long long MOD=1e9+7;
private:
    int fn(int i,int mem,int sum,int minProfit,vector<int>& group,vector<int>& profit,vector<vector<vector<int>>>&dp){
        if(i<0)return(sum>=minProfit);
        if(mem<0)return 0;
        if(dp[i][mem][sum]!=-1)return dp[i][mem][sum];

        int take=0;
        if(mem>=group[i])take=(fn(i-1,mem-group[i],min(minProfit,sum+profit[i]),minProfit,group,profit,dp))%MOD;
        int skip=fn(i-1,mem,sum,minProfit,group,profit,dp);
        return dp[i][mem][sum] = (take+skip)%MOD;
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m=group.size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
        return fn(m-1,n,0,minProfit,group,profit,dp);
    }
};