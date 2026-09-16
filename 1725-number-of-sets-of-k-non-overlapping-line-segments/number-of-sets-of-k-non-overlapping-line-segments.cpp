class Solution {
private:
    int MOD=1e9+7;
    int dp[1002][1002][5];
    int fn(int i,int j,int state,int n,int k){
        if(i>=n-1){
            if(j==k)return 1;
            return 0;
        }
        if(dp[i][j][state+1]!=-1)return dp[i][j][state+1];
        // state=0->skip, 1->started, 2->continue
        int a=fn(i+1,j,0,n,k);
        int b=fn(i+1,j+1,1,n,k);
        int c=0;
        if(state>0)c=fn(i+1,j,2,n,k);
        return dp[i][j][state+1] = (1LL*a+b+c)%MOD;
    }
public:
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return fn(0,0,-1,n,k);
    }
};