class Solution {
long long MOD=1e9+7;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<long long>> dpmax(m,vector<long long>(n,1));
        vector<vector<long long>> dpmin(m,vector<long long>(n,1));

        dpmax[0][0]=grid[0][0];
        for(int i=1;i<m;i++)dpmax[i][0]=dpmin[i][0]=grid[i][0]*dpmax[i-1][0];
        for(int j=1;j<n;j++)dpmax[0][j]=dpmin[0][j]=grid[0][j]*dpmax[0][j-1];

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                long long a=grid[i][j]*dpmax[i-1][j];
                long long b=grid[i][j]*dpmax[i][j-1];
                long long c=grid[i][j]*dpmin[i-1][j];
                long long d=grid[i][j]*dpmin[i][j-1];

                dpmax[i][j]=max({a,b,c,d});
                dpmin[i][j]=min({a,b,c,d});
            }
        }
        return (dpmax[m-1][n-1]<0)?-1:(dpmax[m-1][n-1])%MOD;
    }
};