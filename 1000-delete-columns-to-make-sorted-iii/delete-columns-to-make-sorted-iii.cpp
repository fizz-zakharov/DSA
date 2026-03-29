class Solution {
private:
    int fn(int i,int prev,vector<string>&v,int n,vector<vector<int>>&dp){
        if(i>=n)return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        //skip
        int a=fn(i+1,prev,v,n,dp);

        //take
        bool check=true;
        int b=0;
        if(prev==-1)check=true;
        else{
            for(int j=0;j<v.size();j++){
                if(v[j][i]<v[j][prev]){
                    check=false;
                    break;
                }
            }
        }
        if(check)b=1+fn(i+1,i,v,n,dp);

        return dp[i][prev+1]= max(a,b);
    }
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs[0].size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        int lis=fn(0,-1,strs,n,dp);
        return n-lis;
    }
};