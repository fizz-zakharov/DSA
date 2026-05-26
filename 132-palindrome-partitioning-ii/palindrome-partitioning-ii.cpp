class Solution {
private:
    int fn(int i,int j,string& s,vector<vector<int>>&dp,vector<vector<bool>>&ispal){
        if(i>=j)return 0;
        if(ispal[i][j])return dp[i][j]= 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int a=10000;
        for(int k=i;k<j;k++){
            if(ispal[i][k]){
                a=min(a,1+fn(k+1,j,s,dp,ispal));
            }
        }
        return dp[i][j]=a;
    }
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> ispal(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j]&&(j-i<= 2||ispal[i+1][j-1])){
                    ispal[i][j]=true;
                }
            }
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fn(0,n-1,s,dp,ispal);
    }
};