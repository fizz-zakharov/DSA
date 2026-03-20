class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> ans(m-k+1,vector<int>(n-k+1,0));

        int x=0,y=0;
        for(int i=0;i<m;i++){
            if(m-i<k)continue;
            y=0;
            for(int j=0;j<n;j++){
                if(n-j<k)continue;
                int mn=INT_MAX,mx=INT_MIN;
                vector<int> temp;
                for(int r=0;r<k;r++){
                    for(int c=0;c<k;c++){
                        temp.push_back(grid[i+r][j+c]);
                    }   
                }
                sort(temp.begin(),temp.end());
                int diff=INT_MAX;
                for(int ind=1;ind<temp.size();ind++){
                    if(temp[ind]==temp[ind-1])continue;
                    diff=min(diff,temp[ind]-temp[ind-1]);
                }
                ans[x][y]=(diff!=INT_MAX)?diff:0;
                y++;
            }
            x++;
        }
        return ans;
    }
};