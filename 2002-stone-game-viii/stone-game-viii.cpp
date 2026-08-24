class Solution {
private:
    int n;
    vector<int> dp;
    int fn(int i,vector<int>&v){
        if(i==n)return v[n];
        if(dp[i]!=-1e9)return dp[i];
        int a=fn(i+1,v);
        int b=v[i]-a;
        return dp[i] = max(a,b);
    }
public:
    int stoneGameVIII(vector<int>& stones) {
        n=stones.size();
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+stones[i];
        }
        dp.resize(1e5+2,-1e9);
        int ans=fn(2,pre);
        return ans;
    }
};