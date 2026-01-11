class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>> grid(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            int c=0;
            for(int i=0;i<n;i++){
                if(matrix[i][j]=='0'){
                    c=0;
                    grid[i][j]=0;
                }
                else{
                    c++;
                    grid[i][j]=c;
                }
            }
        }

        // pse matrix
        vector<vector<int>> pse(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++) {
            stack<int> s;
            for (int j = 0; j < m; j++) {
                while (!s.empty() && grid[i][s.top()] >= grid[i][j]) {
                    s.pop();
                }
                pse[i][j] = s.empty() ? -1 : s.top();
                s.push(j);
            }
        }

        // nse matrix
        vector<vector<int>> nse(n, vector<int>(m, m));
        for(int i = 0; i < n; i++) {
            stack<int> s;
            for (int j = m - 1; j >= 0; j--) {
                while (!s.empty() && grid[i][s.top()] >= grid[i][j]) {
                    s.pop();
                }
                nse[i][j] = s.empty() ? m : s.top();
                s.push(j);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int width=nse[i][j]-pse[i][j]-1; 
                ans = max(ans, grid[i][j] * width);
            }
        }
        return ans;
    }
};