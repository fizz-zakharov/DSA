class Solution {
private:
    int dp[202][202];
    int fn(int i,int j){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int a=INT_MAX;
        for(int k=i;k<j;k++){
            a=min(a,k+max(fn(i,k-1),fn(k+1,j)));
        }
        return dp[i][j] = a;
    }
public:
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return fn(1,n);
    }
};