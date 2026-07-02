class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> maxhealth(m,vector<int>(n,INT_MIN));

        queue<pair<int,pair<int,int>>> q;

        const vector<int> dx={0,1,-1,0};
        const vector<int> dy={1,0,0,-1};

        if(health-grid[0][0]<1)return false;
        q.push({health-grid[0][0],{0,0}});
        maxhealth[0][0]=health-grid[0][0];
        while(!q.empty()){
            int hrem=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            if(hrem!=maxhealth[x][y])continue;
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0||nx>=m||ny<0||ny>=n)continue;
                if(hrem-grid[nx][ny]>maxhealth[nx][ny]){
                    maxhealth[nx][ny]=hrem-grid[nx][ny];
                    q.push({hrem-grid[nx][ny],{nx,ny}});
                }
            }
        }
        return (maxhealth[m-1][n-1]>=1)?true:false;
    }
};