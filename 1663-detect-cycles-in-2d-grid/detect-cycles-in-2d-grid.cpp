class Solution {
private:
    const vector<int> dx={0,1,0,-1};
    const vector<int> dy={1,0,-1,0};
    //direction 0->right,1->down,2->left,3->up
    bool dfs(int i,int j,int m,int n,int pi,int pj,vector<vector<char>>&v,vector<vector<int>>&vis){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x==pi && y==pj)continue;
            if(x<m && x>=0 && y<n && y>=0 && v[x][y]==v[i][j]){
                if(vis[x][y])return true;
                if(dfs(x,y,m,n,i,j,v,vis))return true;
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==1)continue;
                bool ch=dfs(i,j,m,n,-1,-1,grid,vis);
                if(ch)return true;
            }
        }
        return false;

    }
};