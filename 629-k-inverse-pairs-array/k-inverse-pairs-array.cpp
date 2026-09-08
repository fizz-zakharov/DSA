class Solution {
public:
    int MOD=1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int i=2;i<=n;i++)dp[i][0]=1;
        dp[1][0]=1;
        for(int i=2;i<=n;i++){
            vector<int> pre(k+2,0);
            for(int j=0;j<=k;j++){
                pre[j+1]=(pre[j]+dp[i-1][j])%MOD;
            }

            for(int j=0;j<=k;j++){
                int l=max(0,j-i+1);
                dp[i][j]=(pre[j+1]-pre[l]+MOD)%MOD;
            }
        }
        return dp[n][k];
    }
};