class Solution {
//vector<vector<int>> visited;
const vector<int> dx={1,0,0,-1};
const vector<int> dy={0,-1,1,0};
private:
    int distance(int i,int j,int x,int y,vector<vector<int>>&v,int m,int n){
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> mindist(m,vector<int>(n,INT_MAX));
        q.push({0,{i,j}});
        mindist[i][j]=0;
        while(!q.empty()){
            int ni=q.front().second.first;
            int nj=q.front().second.second;
            int dist=q.front().first;
            q.pop();
            if(mindist[ni][nj]!=dist)continue;
            for(int k=0;k<4;k++){
                int nx=ni+dx[k];
                int ny=nj+dy[k];
                if(nx<0 || nx>=m || ny<0 || ny>=n || v[nx][ny]==0)continue;
                if(dist+1<mindist[nx][ny]){
                    mindist[nx][ny]=dist+1;
                    q.push({dist+1,{nx,ny}});
                }
            }
        }
        return (mindist[x][y]==INT_MAX)?-1:mindist[x][y];
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m=forest.size();
        int n=forest[0].size();

        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(forest[i][j]>1)v.push_back({forest[i][j],{i,j}});
            }
        }
        sort(v.begin(),v.end());
        int ans=0;
        pair<int,int> start={0,0};
        for(int i=0;i<v.size();i++){
            int a=distance(start.first,start.second,v[i].second.first,v[i].second.second,forest,m,n);
            if(a==-1)return -1;
            ans+=a;
            start={v[i].second.first,v[i].second.second};
        }
        return ans;

    }
};