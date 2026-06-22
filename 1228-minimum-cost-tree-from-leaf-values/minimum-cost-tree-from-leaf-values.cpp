class Solution {
private:
    int dp[42][42];
    int fn(int i,int j,vector<int>&v){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int lm=INT_MIN;
            int rm=INT_MIN;
            for(int t=i;t<=k;t++){
                lm=max(lm,v[t]);
            }
            for(int t=k+1;t<=j;t++){
                rm=max(rm,v[t]);
            }
            ans=min(ans,lm*rm+fn(i,k,v)+fn(k+1,j,v));
        }
        return dp[i][j]=ans;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        return fn(0,n-1,arr);
    }
};