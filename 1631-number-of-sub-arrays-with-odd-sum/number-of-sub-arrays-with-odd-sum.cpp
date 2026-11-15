class Solution {
private:
    int n;
    int MOD=1e9+7;
    int dp[100005][3][3];

    int fn(int i,int prev,int state,vector<int>&v){
        if(prev==-2){
            return (state==1);
        }
        if(i>=n){
            if(state==1)return 1;
            return 0;
        }
        if(dp[i][prev+2][state]!=-1)return dp[i][prev+2][state];
        int ans=0;
        if(prev==-1){
            ans=(ans+fn(i+1,0,v[i]&1,v))%MOD;
            ans=(ans+fn(i+1,-1,0,v))%MOD;
        }
        else{
            ans=(ans+fn(i+1,0,(state+v[i])&1,v))%MOD;
            ans=(ans+fn(i+1,-2,state,v))%MOD;
        }
        return dp[i][prev+2][state] = ans%MOD;
    }
public:
    int numOfSubarrays(vector<int>& arr) {
        n=arr.size();
        memset(dp,-1,sizeof(dp));
        int ans=fn(0,-1,0,arr);
        return ans;
    }
};