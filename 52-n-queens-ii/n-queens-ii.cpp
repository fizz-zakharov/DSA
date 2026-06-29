class Solution {
private:

    bool valid(int i,int j,vector<vector<int>>&v,int n){
        for(int k=0;k<n;k++){
            if(v[i][k]==1)return false;
        }
        for(int k=0;k<n;k++){
            if(v[k][j]==1)return false;
        }
        for(int k=1;i-k>=0 && j+k<n;k++){
            if(v[i-k][j+k]==1)return false;
        }
        for(int k=1;i+k<n && j-k>=0;k++){
            if(v[i+k][j-k]==1)return false;
        }
        for(int k=1;i-k>=0 && j-k>=0;k++){
            if(v[i-k][j-k]==1)return false;
        }
        for(int k=1;i+k<n && j+k<n;k++){
            if(v[i+k][j+k]==1)return false;
        }
        return true;

    }


    int fn(int n,int m,vector<vector<int>>&v){
        if(n==0)return 1;
        int a=0;
        for(int i=0;i<v.size();i++){
            if(valid(m,i,v,v.size())){
                v[m][i]=1;
                a+=fn(n-1,m+1,v);
                v[m][i]=0;
            }
        }
        return a;
    }
public:
    int totalNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<n;i++){
            board[0][i]=1;
            ans+=fn(n-1,1,board);
            board[0][i]=0;
        }
        return ans;
    }
};