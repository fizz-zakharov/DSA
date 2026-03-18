class Solution {
private:
    bool valid(int num, int i, int j, vector<vector<char>>& v){

        for(int k = 0; k < 9; k++){

            if(v[i][k] != '.' && v[i][k] - '0' == num) return false;
            if(v[k][j] != '.' && v[k][j] - '0' == num) return false;
        }

        int startx = (i/3) * 3;
        int starty = (j/3) * 3;

        for(int m = startx; m < startx + 3; m++){
            for(int n = starty; n < starty + 3; n++){
                if(v[m][n] != '.' && v[m][n] - '0' == num)
                    return false;
            }
        }

        return true;
    }

    bool fn(int i, int j, vector<vector<char>>& v){

        if(i == 9) return true;        // solved

        int ni = (j == 8) ? i + 1 : i;
        int nj = (j == 8) ? 0 : j + 1;

        if(v[i][j] != '.')
            return fn(ni, nj, v);

        for(int k = 1; k <= 9; k++){

            if(valid(k, i, j, v)){

                v[i][j] = k + '0';

                if(fn(ni, nj, v))
                    return true;

                v[i][j] = '.';   // backtrack
            }
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        fn(0, 0, board);
    }
};
