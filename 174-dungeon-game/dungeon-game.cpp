class Solution {
private:

    vector<vector<int>>dp;

    bool valid(int i,int j,int k,vector<vector<int>>&v,int m,int n){
        if(i>=m||j>=n)return false;
        k+=v[i][j];
        if(k<=0)return false;
        if(dp[i][j]>=k)return false;

        dp[i][j]=k;
        if(i==m-1&&j==n-1)return true;
        bool a=valid(i+1,j,k,v,m,n);
        bool b=valid(i,j+1,k,v,m,n);

        return a||b;
    }

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int m=dungeon.size();
        int n=dungeon[0].size();

        int low=1,high=1e6;

        int ans;

        while(low<=high){
            int mid=low+(high-low)/2;
            dp.assign(m,vector<int>(n,-1));
            if(valid(0,0,mid,dungeon,m,n)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }

        return ans;
    }
};