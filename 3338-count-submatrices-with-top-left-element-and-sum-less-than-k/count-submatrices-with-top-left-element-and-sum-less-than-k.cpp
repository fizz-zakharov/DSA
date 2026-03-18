class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> precol(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            int sum=0;
            for(int i=0;i<m;i++){
                sum+=grid[i][j];
                precol[i][j]=sum;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=precol[i][j];
                if(sum<=k)ans++;
            }
        }
        return ans;
    }
};