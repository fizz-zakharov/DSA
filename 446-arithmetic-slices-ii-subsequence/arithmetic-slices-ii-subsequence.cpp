class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<long long,int>> dp(n);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long long diff=(long long)nums[i]-nums[j];
                int c=0;
                if(dp[j].find(diff)!=dp[j].end()){
                    c=dp[j][diff];
                    ans+=c;
                }
                dp[i][diff]+=c+1;
            }
        }
        return ans;
    }
};