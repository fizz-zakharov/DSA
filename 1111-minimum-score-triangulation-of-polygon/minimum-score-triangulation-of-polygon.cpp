class Solution {
private:
    int dp[52][52];
    int fn(int i,int j,vector<int>&v){
        if(j-i<2)return 0;
        if(j-i==2)return dp[i][j] = v[i]*v[i+1]*v[j];
        if(dp[i][j]!=-1)return dp[i][j];
        int a=INT_MAX;
        for(int k=i+1;k<j;k++){
            a=min(a,v[i]*v[j]*v[k]+fn(i,k,v)+fn(k,j,v));
        }
        return dp[i][j] = a;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        memset(dp,-1,sizeof(dp));
        return fn(0,n-1,values);
    }
};