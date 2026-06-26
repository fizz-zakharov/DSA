class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> indegree(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j+1<n && matrix[i][j+1]<matrix[i][j]){
                    indegree[i][j]++;
                }
                if(j-1>=0 && matrix[i][j-1]<matrix[i][j])indegree[i][j]++;
                if(i+1<m && matrix[i+1][j]<matrix[i][j])indegree[i][j]++;
                if(i-1>=0 && matrix[i-1][j]<matrix[i][j])indegree[i][j]++;
            }
        }
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(indegree[i][j]==0)q.push({1,{i,j}});
            }
        }
        const vector<int> dx={0,1,-1,0};
        const vector<int> dy={1,0,0,-1};
        int ans=INT_MIN;
        while(!q.empty()){
            int dist=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            ans=max(ans,dist);
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    if(matrix[x][y]<matrix[nx][ny]){
                        indegree[nx][ny]--;
                        if(indegree[nx][ny]==0){
                            q.push({dist+1,{nx,ny}});
                        }
                    }
                }
            }
        }
        return ans;
    }
};