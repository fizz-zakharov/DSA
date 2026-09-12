class Solution {
private:
    const vector<int> dx={0,1,-1,0};
    const vector<int> dy={1,0,0,-1};
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> cal(1e6+2,0);
        vector<vector<int>> vis(m,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        for(int i=1;i<cal.size();i++){
            int val=0;
            while(!pq.empty() && i>pq.top().first){
                queue<pair<int,pair<int,int>>> q;
                q.push({1,{pq.top().second.first,pq.top().second.second}});
                while(!q.empty()){
                    int count=q.front().first;
                    int x=q.front().second.first;
                    int y=q.front().second.second;
                    q.pop();
                    vis[x][y]=1;
                    val++;
                    for(int j=0;j<4;j++){
                        int nx=x+dx[j];
                        int ny=y+dy[j];
                        if(nx>=0 && nx<m && ny>=0 && ny<n){
                            if(vis[nx][ny])continue;
                            vis[nx][ny]=1;
                            if(grid[nx][ny]>=i){
                                pq.push({grid[nx][ny],{nx,ny}});
                            }
                            else{
                                q.push({count+1,{nx,ny}});
                            }
                        }
                    }
                }
                pq.pop();
            }
            cal[i]=cal[i-1]+val;
        }
        vector<int> ans;
        for(auto it:queries){
            ans.push_back(cal[it]);
        }
        return ans;
    }
};