class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();

        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int mxlen=1;
        for(int i=0;i<n;i++)dp[i][i]=1;
        for(int i=0;i<n-1;i++){
            dp[i][i+1]=(s[i]==s[i+1]);
            if(dp[i][i+1])mxlen=2;
        }
        for(int len=3;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                dp[i][j]=(s[i]==s[j]) && dp[i+1][j-1];
                if(dp[i][j])mxlen=max(mxlen,j-i+1);
            }
        }
        string ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j] && j-i+1==mxlen){
                    ans=s.substr(i,j-i+1);
                    break;
                }
            }
        }
        return ans;
    }
};