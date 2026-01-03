class Solution {
int MOD=1e9+7;

private:
    int fn(int i,int p1,int p2,int p3,vector<vector<vector<vector<int>>>>&dp,int n){
        if(i==n)return 1;
        if(dp[i][p1+1][p2+1][p3+1]!=-1)return dp[i][p1+1][p2+1][p3+1];
        
        int c=0;
        for(int c1=0;c1<3;c1++){
            for(int c2=0;c2<3;c2++){
                for(int c3=0;c3<3;c3++){
                    if(c1!=p1&&c2!=p2&&c3!=p3&&c1!=c2&&c2!=c3){
                        c=(c+fn(i+1,c1,c2,c3,dp,n))%MOD;
                    }
                }
            }
        }
        return dp[i][p1+1][p2+1][p3+1]=c;
    }
public:
    int numOfWays(int n) {
        vector<vector<vector<vector<int>>>> dp(n+1,vector<vector<vector<int>>>(4,vector<vector<int>>(4,vector<int>(4, -1))));
        return fn(0,-1,-1,-1,dp,n);
    }
};