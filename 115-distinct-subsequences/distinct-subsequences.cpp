class Solution {
private:
    int dp[1002][1002];
    int fn(int i,int j,string& s,string& t,int n,int m){
        if(j>=m)return 1;
        if(i>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int a=0;
        if(s[i]==t[j]){
            a+=fn(i+1,j+1,s,t,n,m);
        }
        a+=fn(i+1,j,s,t,n,m);

        return dp[i][j] = a;
    }
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        memset(dp,-1,sizeof(dp));
        int ans=fn(0,0,s,t,n,m);
        return ans;
    }
};