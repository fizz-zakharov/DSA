class Solution {
private:
    int n;
    int dp[16][((1<<14)+2)];
    int fn(int i,int mask,vector<int>&v1,vector<int>&v2){
        if(i>=n)return 0;
        if(dp[i][mask]!=-1)return dp[i][mask];
        int sum=1e9;
        for(int j=0;j<n;j++){
            if(mask&(1<<j))continue;
            int newmask=mask|(1<<j);
            sum=min(sum,(v1[i]^v2[j])+fn(i+1,newmask,v1,v2));
        }
        return dp[i][mask] = sum;
    }
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        memset(dp,-1,sizeof(dp));
        return fn(0,0,nums1,nums2);
    }
};