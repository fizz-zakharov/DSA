class Solution {
private:
    int fn(int i,int time,vector<int>&v,vector<vector<int>>&dp){
        int n=v.size();
        if(i>=n)return 0;
        if(dp[i][time]!=-1)return dp[i][time];

        int ans=0;
        //pick
        ans=v[i]*time+fn(i+1,time+1,v,dp);

        //not pick
        ans=max(ans,fn(i+1,time,v,dp));

        return dp[i][time]= ans;
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<int> v=satisfaction;
        reverse(v.begin(),v.end());

        vector<vector<int>> dp1(n,vector<int>(n+1,-1));
        vector<vector<int>> dp2(n,vector<int>(n+1,-1));
        

        return max(fn(0,1,satisfaction,dp1),fn(0,1,v,dp2));
    }
};