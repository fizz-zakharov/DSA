class Solution {
private:
    int dp[100006];
    int fn(int rem){
        if(dp[rem]!=-1)return dp[rem];
        int ans=0;
        for(int i=1;i*i<=rem;i++){
            if(rem-i*i>=0){
                ans=ans|(fn(rem-i*i)==0);
            }
        }
        return dp[rem] = ans;
    }
public:
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        if(fn(n)==1)return true;
        return false;
    }
};