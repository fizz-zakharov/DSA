class Solution {
private:
    long long fn(int i,int state,int k,vector<int>&prices,vector<vector<vector<long long>>>&dp){
        int n=prices.size();
        if(k==0)return 0;
        if(i==n){
            return(state==0)?0:-1e12;
        }
        if(dp[i][state][k]!=-1)return dp[i][state][k];
        long long profit=INT_MIN;
        if(state==0){
            profit=max(profit,fn(i+1,0,k,prices,dp)); //skip
            profit=max(profit,-prices[i]+fn(i+1,1,k,prices,dp)); //buy
            profit=max(profit,prices[i]+fn(i+1,2,k,prices,dp)); //short sell
        }
        if(state==1){
            profit=max(profit,fn(i+1,1,k,prices,dp)); //skip
            profit=max(profit,prices[i]+fn(i+1,0,k-1,prices,dp)); //sell
        }
        if(state==2){
            profit=max(profit,fn(i+1,2,k,prices,dp)); //skip
            profit=max(profit,-prices[i]+fn(i+1,0,k-1,prices,dp)); //buy back
        }
        return dp[i][state][k]= profit;
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(3, vector<long long>(k+1, -1)));

        return fn(0,0,k,prices,dp);
    }
};