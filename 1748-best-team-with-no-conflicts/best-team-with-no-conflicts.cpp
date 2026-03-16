class Solution {
private:
    int fn(int i,int j,vector<pair<int,int>>&v,vector<vector<int>>&dp){
        int n=v.size();
        if(i>=n)return 0;
        if(dp[i][j+1]!=-1)return dp[i][j+1];

        int curscore=v[i].first;
        int curage=v[i].second;
        int ans=INT_MIN;
        //take case
        if(j<=curage)ans=curscore+fn(i+1,curage,v,dp);

        //not take case
        ans=max(ans,fn(i+1,j,v,dp));

        return dp[i][j+1]= ans;

    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=scores.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({scores[i],ages[i]});
        }
        sort(v.begin(),v.end());
        int maxage=0;
        for(int i=0;i<n;i++)maxage=max(maxage,ages[i]);

        vector<vector<int>> dp(n,vector<int>(maxage+2,-1));
        return fn(0,-1,v,dp);
    }
};