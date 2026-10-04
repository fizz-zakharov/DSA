class Solution {
private:
    int n;
    int dp[105][105];
    int fn(int i,int j,string& s){
        if(j<0)return 0;
        if(i>=n)return (j==0);
        if(dp[i][j]!=-1)return dp[i][j];
        int a=0,b=0,c=0;
        if(s[i]=='(')a=fn(i+1,j+1,s);
        else if(s[i]==')')b=fn(i+1,j-1,s);
        else c=(fn(i+1,j+1,s)||fn(i+1,j-1,s)||fn(i+1,j,s));
        return dp[i][j] = (a||b||c);
    }
public:
    bool checkValidString(string s) {
        n=s.size();
        memset(dp,-1,sizeof(dp));
        return fn(0,0,s);
    }
};