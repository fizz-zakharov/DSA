class Solution {
private:
    const vector<int> dx = {0, 1, -1, 0};
    const vector<int> dy = {1, 0, 0, -1};
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int k = 0;
        int startx = 0, starty = 0;
        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'L') {
                    litter_id[i][j] = k++;
                }
                if (classroom[i][j] == 'S') {
                    startx = i;
                    starty = j;
                }
            }
        }
        if (k == 0) return 0;
        int all_litter = (1 << k) - 1;

        // Stores the maximum remaining energy seen at (x, y, mask).
        // Drops dimension from 4D to 3D, pruning redundant states and fixing TLE.
        vector<vector<vector<int>>> max_e(m, vector<vector<int>>(n, vector<int>(all_litter + 1, -1)));

        // {moves, i, j, mask, rem_energy}
        queue<array<int, 5>> q;
        q.push({0, startx, starty, 0, energy});
        max_e[startx][starty][0] = energy;

        while (!q.empty()) {
            auto [moves, i, j, mask, rem_energy] = q.front();
            q.pop();

            if (mask == all_litter) return moves;
            if (rem_energy < max_e[i][j][mask]) continue; // strictly worse energy for the same steps/mask
            if (rem_energy == 0) continue;

            for (int d = 0; d < 4; d++) {
                int x = i + dx[d];
                int y = j + dy[d];
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                if (classroom[x][y] == 'X') continue;

                int newmask = mask;
                int newenergy = (classroom[x][y] == 'R') ? energy : rem_energy - 1;
                if (classroom[x][y] == 'L') {
                    newmask |= (1 << litter_id[x][y]);
                }

                // Prune: only explore if we reach this cell and mask with strictly higher energy
                if (newenergy > max_e[x][y][newmask]) {
                    max_e[x][y][newmask] = newenergy;
                    q.push({moves + 1, x, y, newmask, newenergy});
                }
            }
        }
        return -1;
    }
};