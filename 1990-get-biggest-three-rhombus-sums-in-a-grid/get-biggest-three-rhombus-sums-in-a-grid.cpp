class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> s;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                s.insert(grid[r][c]);
                for(int k = 1; r-k >= 0 && r+k < m && c-k >= 0 && c+k < n; k++){
                    int sum = 0;
                    for(int i=0;i<k;i++)sum+=grid[r-k+i][c+i];
                    for(int i=0;i<k;i++)sum+=grid[r+i][c+k-i];
                    for(int i=0;i<k;i++)sum+=grid[r+k-i][c-i];
                    for(int i=0;i<k;i++)sum+=grid[r-i][c-k+i];
                    s.insert(sum);
                }
            }
        }

        vector<int> ans;
        for (auto it = s.rbegin(); it != s.rend() && ans.size() < 3;it++)ans.push_back(*it);

        return ans;
    }
};
