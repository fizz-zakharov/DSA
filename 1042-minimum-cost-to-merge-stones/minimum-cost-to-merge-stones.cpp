class Solution {
private:
    int dp[32][32];
    int fn(int i,int j,int k,vector<int>&v,vector<int>&pre){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int m=i;m<j;m+=(k-1)){
            ans=min(ans,fn(i,m,k,v,pre)+fn(m+1,j,k,v,pre));
        }
        if((j-i)%(k-1)==0){
            if(i==0)ans+=pre[j];
            else ans+=pre[j]-pre[i-1];
        }
        return dp[i][j] = ans;
    }
public:
    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();
        if((n-1)%(k-1)!=0)return -1;
        vector<int> pre(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=stones[i];
            pre[i]=sum;
        }
        memset(dp,-1,sizeof(dp));
        return fn(0,n-1,k,stones,pre);

    }
};