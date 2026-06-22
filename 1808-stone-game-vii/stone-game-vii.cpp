class Solution {
private:
    int dp[1002][1002];
    int fn(int i,int j,int sum,vector<int>&v){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        // a and b will calc the diff between alice turn score - bob turn score on first call
        int a=sum-v[i] - fn(i+1,j,sum-v[i],v);
        int b=sum-v[j] - fn(i,j-1,sum-v[j],v);
        return dp[i][j] = max(a,b);
    }
public:
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=stones[i];
        }
        memset(dp,-1,sizeof(dp));
        return fn(0,n-1,sum,stones);
    }
};