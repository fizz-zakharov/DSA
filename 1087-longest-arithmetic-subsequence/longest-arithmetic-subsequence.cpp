class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(1002));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff=nums[j]-nums[i];
                dp[j][diff+500]=max(dp[i][diff+500],1+dp[i][diff+500]);
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<1002;j++){
                ans=max(ans,dp[i][j]);
            }
        }
        return ans+1;
    }
};