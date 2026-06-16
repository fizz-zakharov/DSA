/*
    for a window of (i,j) we can make a cluster of houses from i->x
    and x will go from i->j
    and in each cluster we will put mailbox on house[(i+x)/2] and then we'll move to 
    the next window i.e. (x+1,j) so that will make this problem of partition dp


*/


class Solution {
private:
    long long fn(int i,int j,int k,vector<int>&v,vector<vector<vector<long long>>>&dp){
        if(i>j)return 0;
        if(k==0)return INT_MAX;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        long long ans=INT_MAX;
        for(int x=i;x<=j;x++){
            int h=(i+x)/2;
            int cost=0;
            for(int p=i;p<=x;p++){
                cost+=abs(v[p]-v[h]);
            }
            ans=min(ans,cost+fn(x+1,j,k-1,v,dp));
        }
        return dp[i][j][k] = ans;
    }
public:
    int minDistance(vector<int>& houses, int k) {
        int n=houses.size();
        sort(houses.begin(),houses.end());

        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(n,vector<long long>(n+1,-1)));
    
        return fn(0,n-1,k,houses,dp);
    }
};