class Solution {
private:
    int MOD=1e9+7;
    int n;
    int ans=0;
    int dp[105][105][105];

    long long binexp(long long x,long long k){
        if(k==0)return 1;
        long long ans=1;
        if(k&1){
            ans=(ans*x)%MOD;
            k--;
        }
        x=(x*x)%MOD;
        return (((ans)%MOD)*(binexp(x,k/2)%MOD))%MOD;
    }

    int fn(int i,int sum,int taken,vector<int>&v){
        if(sum<0)return 0;
        if(i>=n){
            if(sum==0)return binexp(2,n-taken);
            return 0;
        }
        if(dp[i][sum][taken]!=-1)return dp[i][sum][taken];
        int a=fn(i+1,sum,taken,v);
        int b=fn(i+1,sum-v[i],taken+1,v);
        
        return dp[i][sum][taken] = (a+b)%MOD;
    }

public:
    int sumOfPower(vector<int>& nums, int k) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return fn(0,k,0,nums);
        
    }
};