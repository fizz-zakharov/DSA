class Solution {
private:
    bool fn(int i,int j,int k,string& s1, string& s2, string& s3,vector<vector<vector<int>>>&dp){
        if(k<0)return (i<0&&j<0);
        if(dp[i+1][j+1][k]!=-1)return dp[i+1][j+1][k];

        bool a=false;
        if(i>=0&&s3[k]==s1[i])a=fn(i-1,j,k-1,s1,s2,s3,dp);
        bool b=false;
        if(j>=0&&s3[k]==s2[j])b=fn(i,j-1,k-1,s1,s2,s3,dp);
        
        return dp[i+1][j+1][k]= (a||b);

    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int s=s3.size();
        if(n+m!=s)return false;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(s,-1))); 

        return fn(n-1,m-1,s-1,s1,s2,s3,dp);
    }
};