class Solution {
private:
    vector<int> target={0,0,0};
    long long dp[30002];
    long long fn(int i,vector<vector<int>>&v){
        if(i>=v.size())return 0;
        if(dp[i]!=-1)return dp[i];
        long long a=fn(i+1,v);
        long long b=0;
        target[0]=v[i][1];
        auto it=lower_bound(v.begin(),v.end(),target);
        if(it==v.end())b=v[i][2]+v[i][1]-v[i][0];
        else{
            int ind=it-v.begin();
            b=v[i][2]+v[i][1]-v[i][0] + fn(ind,v);
        }
        return dp[i] = max(a,b);
        
    }
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int m=rides.size();
        sort(rides.begin(),rides.end());
        memset(dp,-1,sizeof(dp));
        return fn(0,rides);
    }
};