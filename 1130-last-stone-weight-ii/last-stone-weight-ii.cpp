class Solution {
private:    
    int fn(int i,int weight,vector<int>&v,int sum,vector<vector<int>>&dp){
        if(i>=v.size()){
            return abs(sum-2*weight);
        }
        if(dp[i][weight]!=-1)return dp[i][weight];
        int a=fn(i+1,weight,v,sum,dp);
        int b=fn(i+1,weight+v[i],v,sum,dp);

        return dp[i][weight]= min(a,b);

    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=stones[i];
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return fn(0,0,stones,sum,dp);
    }
};