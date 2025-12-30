class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        if(n<3||m<3)return 0;
        for(int i=0;i<n;i++){
            if(n-i<3)break;
            for(int j=0;j<m;j++){
                if(m-j<3)break;
                int sum=grid[i][j]+grid[i][j+1]+grid[i][j+2];
                set<int> s;
                for(int p=0;p<3;p++){
                    for(int q=0;q<3;q++){
                        s.insert(grid[i+p][j+q]);
                    }
                }
                if(s.size()!=9)continue;
                if(*s.begin()!=1||*prev(s.end())!=9)continue;
                if(grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2]!=sum)continue; //2nd row
                if(grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]!=sum)continue; //3rd row
                if(grid[i][j]+grid[i+1][j]+grid[i+2][j]!=sum)continue; //1st col
                if(grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1]!=sum)continue; //2nd col
                if(grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2]!=sum)continue; //3rd col
                if(grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2]!=sum)continue; //pos diagnol
                if(grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j]!=sum)continue; //neg diagnol 
                ans++;
            }
        }
        return ans;
    }
};