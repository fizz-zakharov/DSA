class Solution {
private:
    int dp[102][12][3];
    int fn(int i,int prev,int taken,string& s,int n){
        if(i>=n)return 1;
        if(dp[i][prev+1][taken]!=-1)return dp[i][prev+1][taken];
        int cur=s[i]-'0';
        int ans=0;
        if(taken==0){
            if(cur==0)ans=0;
            else{
                ans+=fn(i+1,cur,0,s,n);
                if(i+1<n)ans+=fn(i+1,cur,1,s,n);
            }
        }
        else{
            if(prev==1){
                ans+=fn(i+1,cur,0,s,n);
            }
            else if(prev==2 && cur<=6){
                ans+=fn(i+1,cur,0,s,n);
            }
        }
        return dp[i][prev+1][taken] = ans;
    }
public:
    int numDecodings(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return fn(0,-1,0,s,n);
    }
};