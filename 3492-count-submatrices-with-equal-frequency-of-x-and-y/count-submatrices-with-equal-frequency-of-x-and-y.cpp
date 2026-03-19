class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<pair<int,int>>> precol(m,vector<pair<int,int>>(n,{0,0}));

        for(int j=0;j<n;j++){
            int s1=0,s2=0;
            for(int i=0;i<m;i++){
                if(grid[i][j]=='X')s1++;
                if(grid[i][j]=='Y')s2++;
                precol[i][j].first=s1;
                precol[i][j].second=s2;
            }
        }

        int ans=0;
        for(int i=0;i<m;i++){
            int s1=0,s2=0;
            for(int j=0;j<n;j++){
                s1+=precol[i][j].first;
                s2+=precol[i][j].second;
                if(s1>0&&s1==s2)ans++;
            }
        }
        return ans;
    }
};