class Solution {
private:
    int up(int i, int j, vector<vector<int>>& mine, int n,
           vector<vector<int>>& dp){
        if(i < 0 || mine[i][j]) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = 1 + up(i-1, j, mine, n, dp);
    }

    int down(int i, int j, vector<vector<int>>& mine, int n,
             vector<vector<int>>& dp){
        if(i >= n || mine[i][j]) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = 1 + down(i+1, j, mine, n, dp);
    }

    int left(int i, int j, vector<vector<int>>& mine, int n,
             vector<vector<int>>& dp){
        if(j < 0 || mine[i][j]) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = 1 + left(i, j-1, mine, n, dp);
    }

    int right(int i, int j, vector<vector<int>>& mine, int n,
              vector<vector<int>>& dp){
        if(j >= n || mine[i][j]) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = 1 + right(i, j+1, mine, n, dp);
    }

public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {

        vector<vector<int>> mine(n, vector<int>(n, 0));
        for(auto &it : mines)
            mine[it[0]][it[1]] = 1;

        vector<vector<int>> dp1(n, vector<int>(n, -1));
        vector<vector<int>> dp2(n, vector<int>(n, -1));
        vector<vector<int>> dp3(n, vector<int>(n, -1));
        vector<vector<int>> dp4(n, vector<int>(n, -1));

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                if(mine[i][j]) continue;

                int a = up(i-1, j, mine, n, dp1);
                int b = down(i+1, j, mine, n, dp2);
                int c = left(i, j-1, mine, n, dp3);
                int d = right(i, j+1, mine, n, dp4);

                int order = 1 + min({a, b, c, d});
                ans = max(ans, order);
            }
        }

        return ans;
    }
};
