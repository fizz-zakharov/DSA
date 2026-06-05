class Solution {
private:
    int fn(int i,int tight,int prev,string& s,vector<vector<vector<int>>>&dp){
        if(i>=s.size())return 1;
        if(dp[i][tight][prev+1]!=-1)return dp[i][tight][prev+1];
        int ans=0;
        if(tight){
            if(s[i]-'0'==1){
                if(prev!=1)ans+=fn(i+1,1,1,s,dp);
                ans+=fn(i+1,0,0,s,dp);
            }
            else{
                ans+=fn(i+1,1,0,s,dp);
            }
        }
        else{
            if(prev!=1)ans+=fn(i+1,0,1,s,dp);
            ans+=fn(i+1,0,0,s,dp);
        }
        return dp[i][tight][prev+1]= ans;
    }
public:
    int findIntegers(int n) {
        string s;
        while(n){
            if(1&n){
                s.push_back('1');
            }
            else{
                s.push_back('0');
            }
            n=(n>>1);
        }
        reverse(s.begin(),s.end());
        vector<vector<vector<int>>> dp(s.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return fn(0,1,-1,s,dp);

    }
};