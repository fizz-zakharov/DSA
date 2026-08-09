class Solution {
private:
    int n;
    int dp[102][204];
    int fn(int i,int j,vector<int>&v){
        if(i>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int sum=0;
        int ans=0;
        for(int k=i;k<=min(n-1,i+j-1);k++){
            sum+=v[k];
            int m=j/2;
            int x=k-i+1;
            int M=max(m,x);
            int total_rem = 0;
            for(int r=k+1;r<n;r++)total_rem+=v[r];
            int temp=(k+1>=n)?0:1e9;
            for(int l=1;l<=2*M && k+l<=n;l++){
                temp=min(temp,fn(k+1,2*M,v));
            }
            ans=max(ans,sum+(total_rem-temp));
        }
        return dp[i][j] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        memset(dp,-1,sizeof(dp));
        int ans=fn(0,2,piles);
        return ans;
    }
};