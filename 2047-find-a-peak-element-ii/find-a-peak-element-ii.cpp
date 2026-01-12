class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        int i=0,j=0;
        while(1){
            // cout<<i<<" "<<j<<'\n';
            if((i-1<0||mat[i][j]>mat[i-1][j])&&(i+1>n-1||mat[i][j]>mat[i+1][j])&&(j-1<0||mat[i][j]>mat[i][j-1])&&(j+1>m-1||mat[i][j]>mat[i][j+1])) return {i,j};
            int ti=i,tj=j;
            if(j-1>=0&&mat[ti][tj]<mat[i][j-1]) ti=i,tj=j-1;
            if(j+1<m&&mat[ti][tj]<mat[i][j+1]) tj=j+1,ti=i;
            if(i-1>=0&&mat[ti][tj]<mat[i-1][j]) ti=i-1,tj=j;
            if(i+1<n&&mat[ti][tj]<mat[i+1][j]) ti=i+1,tj=j;
            i=ti;
            j=tj;
        }
        // return {1,1};
    }
};