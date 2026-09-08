class Solution {
private:
    int MOD=1e9+7;
    long long dp[2002];
    long long fn(int i,string& s){
        if(i==0)return 2;
        if(dp[i]!=-1)return dp[i];
        long long a=0;
        for(int j=i-1;j>=0;j--){
            if(s[i]==s[j]){
                a=(j==0)?1:fn(j-1,s);
                break;
            }
        }
        return dp[i] = (2*fn(i-1,s)-a+MOD)%MOD;
    }
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        long long ans=(fn(n-1,s)-1+MOD)%MOD;
        return ans;
    }
};