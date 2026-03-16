class Solution {
private:
    int fn(int i,int j,vector<int>&v,vector<int>&w,vector<vector<int>>&dp){
        int n=v.size();
        if(i>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        int ans=INT_MAX;
        int pv=v[i-1];
        int pw=w[i-1];

        if(j)swap(pv,pw);

        //no swap
        if(v[i]>pv&&w[i]>pw)ans=fn(i+1,0,v,w,dp);

        //swap case
        if(v[i]>pw&&w[i]>pv)ans=min(ans,1+fn(i+1,1,v,w,dp));

        return dp[i][j]=ans;

    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);

        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return fn(1,0,nums1,nums2,dp);


    }
};