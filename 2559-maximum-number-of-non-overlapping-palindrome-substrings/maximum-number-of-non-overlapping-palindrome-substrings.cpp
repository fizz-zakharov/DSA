class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n=s.size();
        if(k==1)return n;
        vector<vector<bool>> dp(n,vector<bool>(n,false));

        for(int i=0;i<n;i++)dp[i][i]=true;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1])dp[i][i+1]=true;
        }
        for(int len=3;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                dp[i][j]=(s[i]==s[j])&&dp[i+1][j-1];
            }
        }
        int ans=0;

        for(int i=0;i<n;i++){
            int j=i+1;
            while(j<n){
                if(j-i+1>=k){
                    if(dp[i][j]){
                        ans++;
                        i=j;
                        break;
                    }
                    bool ch=false;
                    for(int r=j;r>i;r--){
                        if(j-r+1>=k){
                            if(dp[r][j]){
                                ans++;
                                i=j;
                                ch=true;
                                break;
                            }
                        }
                    }
                    if(ch)break;
                }
                j++;
            }
        }
        return ans;
    }
};