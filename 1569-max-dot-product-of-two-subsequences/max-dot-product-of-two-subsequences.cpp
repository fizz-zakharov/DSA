class Solution {
private:
    long long fn(int i,int j,bool check,vector<int>&nums1,vector<int>&nums2,vector<vector<vector<int>>>&dp){
        if(i<0||j<0){
            if(check)return 0;
            return -1e9;
        }
        if(dp[i][j][check]!=-1e9)return dp[i][j][check];
        long long a=nums1[i]*nums2[j]+fn(i-1,j-1,true,nums1,nums2,dp); //take both no.s
        long long b=fn(i-1,j,check,nums1,nums2,dp); //skip 1st num
        long long c=fn(i,j-1,check,nums1,nums2,dp); //skip 2nd num
        long long d=fn(i-1,j-1,check,nums1,nums2,dp); //skip both nums

        return dp[i][j][check]= max({a,b,c,d});
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(2,-1e9)));
        return fn(n-1,m-1,false,nums1,nums2,dp);
    }
};