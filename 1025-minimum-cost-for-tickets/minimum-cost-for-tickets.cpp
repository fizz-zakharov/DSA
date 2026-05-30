class Solution {
const vector<int> util={1,7,30};
private:
    int fn(int i,int j,int prev,vector<int>&v,vector<int>&c,vector<vector<vector<int>>>&dp){
        if(i>=v.size()){
            return 0;
        }
        if(dp[i][j][prev]!=-1)return dp[i][j][prev];
        int a=INT_MAX;
        if(v[i]<=prev+j-1){
            a=fn(i+1,j,prev,v,c,dp);
        }
        int b=INT_MAX;
        for(int k=0;k<3;k++){
            b=min(b,c[k]+fn(i+1,util[k],v[i],v,c,dp));
        }
        return dp[i][j][prev]= min(a,b);
    
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        sort(days.begin(),days.end());
        int n=days[days.size()-1];
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(31,vector<int>(n+1,-1)));
        return fn(0,0,0,days,costs,dp);
    }
};