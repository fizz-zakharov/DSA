class Solution {
private:
    int dp[52][52][52][52];
    int fn(int i,int j,int x,int y,vector<vector<int>>&v,int n){
        if(i>=n || j>=n || x>=n || y>=n || v[i][j]==-1 || v[x][y]==-1)return -1e9;
        if(i==n-1 && j==n-1){
            return (v[i][j]==1)?1:0;
        }
        if(x==n-1 && y==n-1){
            return (v[x][y]==1)?1:0;
        }
        if(dp[i][j][x][y]!=-1)return dp[i][j][x][y];
        
        int a=0,b=0,c=0,d=0;
        int add=0;
        bool ch=true;
        if(i==x && j==y){
            if(v[i][j]==1)add++;
            ch=false;
        }
        if(v[i][j]==1){
            a=1;
            b=1;
            if(ch)add++;
        }
        if(v[x][y]==1){
            c=1;
            d=1;
            if(ch)add++;
        }

        a=add+fn(i+1,j,x+1,y,v,n);
        b=add+fn(i+1,j,x,y+1,v,n);
        c=add+fn(i,j+1,x+1,y,v,n);
        d=add+fn(i,j+1,x,y+1,v,n);

        return dp[i][j][x][y] = max({a,b,c,d});

    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        memset(dp,-1,sizeof(dp));
        return max(0,fn(0,0,0,0,grid,n));
    }
};