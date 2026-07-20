class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        ans=grid;
        while(k--){
            vector<int> temp(m,0);
            for(int i=0;i<m;i++)temp[i]=ans[i][0];
            vector<int> rest;
            for(int j=1;j<n;j++){
                for(int i=0;i<m;i++){
                    int next=ans[i][j];
                    ans[i][j]=temp[i];
                    temp[i]=next;
                }
            }
            ans[0][0]=grid[m-1][n-1];
            for(int i=0;i<m-1;i++)rest.push_back(grid[i][n-1]);
            for(int i=1;i<m;i++)ans[i][0]=rest[i-1];
            grid=ans;
        }
        return ans;
    }
};