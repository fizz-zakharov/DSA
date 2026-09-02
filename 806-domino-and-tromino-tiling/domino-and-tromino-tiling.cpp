class Solution {
private:
    long long MOD=1e9+7;
public:
    int numTilings(int n) {
        if(n==1)return 1;
        vector<long long> dp(n+1,0);
        vector<long long> p(n+1,0);
        dp[0]=1;
        dp[1]=1;
        p[0]=0;
        p[1]=0;
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2]+2*p[i-1])%MOD;
            p[i]=(dp[i-2]+p[i-1])%MOD;
        }
        return dp[n];
    }
};