class Solution {
private:
    bool bfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        int dx[4]={0,1,-1,0};
        int dy[4]={1,0,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int x=it.first;
            int y=it.second;
            if(x==n-1)return true;
            for(int  k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny]&& grid[nx][ny]==0){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        return false;
    }

    bool valid(int mid,int row,int col,vector<vector<int>>& cells){
        int n=cells.size();
        vector<vector<int>> grid(row,vector<int>(col,0));
        for(int  i=0;i<=mid;i++){
            int r=cells[i][0];
            int c=cells[i][1];
            grid[r-1][c-1]=1;
        }
        vector<vector<int>> visited(row,vector<int>(col,0));
        for(int  j=0;j<col;j++){
            if(grid[0][j]==0){
                if(bfs(0,j,grid,visited))return true;
            }
        }
        return false;
    }

public:
    int latestDayToCross(int row,int col,vector<vector<int>>& cells){
        int n=cells.size();
        int low=0,high=n-1;
        int ans=INT_MIN;
        while(low<=high){
            int mid=(high+low)>>1;
            if(valid(mid,row,col,cells)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans+1;
    }
};
