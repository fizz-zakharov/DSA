class Solution {
private:
    const vector<int> dx={0,1,-1,0};
    const vector<int> dy={1,0,0,-1};
    void dfs(int i,int j,vector<vector<int>>&v1,vector<vector<int>>&v2,vector<vector<int>>&vis,bool& ch,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j]==1 || v2[i][j]==0)return;
        vis[i][j]=1;
        if(v1[i][j]==0 && v2[i][j]==1){
            ch=false;
        }
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            dfs(nx,ny,v1,v2,vis,ch,m,n);
        }
        return;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size();
        int n=grid1[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        bool ch=true;
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j])continue;
                if(grid2[i][j]==1){
                    dfs(i,j,grid1,grid2,vis,ch,m,n);
                    if(ch==true)ans++;
                }
                ch=true;
            }
        }
        return ans;

    }
};