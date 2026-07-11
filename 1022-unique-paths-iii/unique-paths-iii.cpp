class Solution {
private:
    int fn(int i,int j,int endi,int endj,int ct,vector<vector<int>>&v,vector<vector<int>>&vis,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n || v[i][j]==-1 || vis[i][j]==1)return 0;
        if(i==endi && j==endj){
            if(ct==0)return 1;
            else return 0;
        }

        vis[i][j]=1;
        int a=fn(i+1,j,endi,endj,ct-1,v,vis,m,n);
        int b=fn(i,j+1,endi,endj,ct-1,v,vis,m,n);
        int c=fn(i-1,j,endi,endj,ct-1,v,vis,m,n);
        int d=fn(i,j-1,endi,endj,ct-1,v,vis,m,n);
        vis[i][j]=0;

        return a+b+c+d;

    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int c=1;
        int starti,startj,endi,endj;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)c++;
                if(grid[i][j]==1){
                    starti=i;
                    startj=j;
                }
                if(grid[i][j]==2){
                    endi=i;
                    endj=j;
                }
            }
        }
        return fn(starti,startj,endi,endj,c,grid,vis,m,n);
    }
};