class Solution {
private:
    int dp[72][4902];
    int fn(int i,int sum,vector<vector<int>>& v,int target,int m,int n){
        if(i>=m){
            return abs(sum-target);
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        int a=1e9;
        for(int j=0;j<n;j++){
            a=min(a,fn(i+1,sum+v[i][j],v,target,m,n));
            //if(sum+v[i][j]>target)break;
        }

        return dp[i][sum] = a;
    }
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m=mat.size();
        int n=mat[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=fn(0,0,mat,target,m,n);
        
        return ans;
    }
};