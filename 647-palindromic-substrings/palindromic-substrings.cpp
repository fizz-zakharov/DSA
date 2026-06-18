class Solution {
private:    
    int fn(int i,int j,string& s,vector<vector<int>>&dp){
        if(i>=j){
            if(i==j)return 1;
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        for(int k=i;k<=j;k++){
            bool ch=true;
            for(int x=i;x<=(i+k)/2;x++){
                if(s[x]!=s[i+k-x]){
                    ch=false;
                    break;
                }
            }
            if(ch){
                ans++;
            }
        }
        return dp[i][j] = ans+fn(i+1,j,s,dp);
    }
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fn(0,n-1,s,dp);
    }
};