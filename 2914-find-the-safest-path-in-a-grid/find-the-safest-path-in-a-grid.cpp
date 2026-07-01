class Solution {
private:
    const vector<int> dx={0,1,-1,0};
    const vector<int> dy={1,0,0,-1};
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> mindist(n,vector<int>(n,INT_MAX));

        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({0,{i,j}});
                    mindist[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int dist=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0 || nx>=n || ny<0 || ny>=n)continue;
                if(dist+1<mindist[nx][ny]){
                    mindist[nx][ny]=dist+1;
                    q.push({dist+1,{nx,ny}});
                }
            }
        }

        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({mindist[0][0],{0,0}});
        vector<vector<int>> ans(n,vector<int>(n,INT_MIN));
        ans[0][0]=mindist[0][0];
        while(!pq.empty()){
            int dist=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(x==n-1 && y==n-1)return dist;
            if(ans[x][y]!=dist)continue;
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0 || nx>=n || ny<0 || ny>=n)continue;
                int safe=min(dist,mindist[nx][ny]);
                if(safe>ans[nx][ny]){
                    ans[nx][ny]=safe;
                    pq.push({safe,{nx,ny}});
                }
            }
        }
        return 0;
    }
};