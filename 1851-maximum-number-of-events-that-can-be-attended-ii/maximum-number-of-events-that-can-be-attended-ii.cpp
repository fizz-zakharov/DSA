class Solution {
private:
    vector<int> target={INT_MAX,INT_MAX,INT_MAX};
    int fn(int i,int k,vector<vector<int>>&v,vector<vector<int>>&dp){
        if(i>=v.size())return 0;
        if(k==0)return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        int a=fn(i+1,k,v,dp);
        int b=0;
        target[0]=v[i][1];
        auto it=upper_bound(v.begin(),v.end(),target);
        if(it==v.end())b=v[i][2];
        else{
            int ind=it-v.begin();
            b=v[i][2]+fn(ind,k-1,v,dp);
        }
        return dp[i][k] = max(a,b);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return fn(0,k,events,dp);
    }
};