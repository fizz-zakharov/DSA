class Solution {
private:
    int n;
    int dp[502][502];
    int fn(int i,int j,vector<int>&v,vector<int>&pre){
        if(i==j){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        for(int k=i;k<j;k++){
            int lsum=pre[k+1]-pre[i];
            int rsum=pre[j+1]-pre[k+1];
            if(lsum==rsum){
                ans=max(ans,lsum+max(fn(i,k,v,pre),fn(k+1,j,v,pre)));
            }
            else if(lsum>rsum){
                ans=max(ans,rsum+fn(k+1,j,v,pre));
            }
            else ans=max(ans,lsum+fn(i,k,v,pre));
        }
        return dp[i][j] = ans;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        n=stoneValue.size();
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+stoneValue[i];
        }
        memset(dp,-1,sizeof(dp));
        int ans=fn(0,n-1,stoneValue,pre);
        return ans;
    }
};