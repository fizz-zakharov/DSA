class Solution {
private:
    const vector<int> dx={0,1,-1,0};
    const vector<int> dy={1,0,0,-1};
    void dfs(int i,int j,int m,int n,vector<vector<int>>&v,vector<vector<int>>&vis,bool& ch){
        if(i<0||i>=m||j<0||j>=n||vis[i][j]||v[i][j]==1)return;
        vis[i][j]=1;
        if(i==0||i==m-1||j==0||j==n-1)ch=true;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            dfs(x,y,m,n,v,vis,ch);
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && vis[i][j]!=1){
                    bool ch=false;
                    dfs(i,j,m,n,grid,vis,ch);
                    if(!ch)ans++;
                }
                
            }
        }
        return ans;
    }
};