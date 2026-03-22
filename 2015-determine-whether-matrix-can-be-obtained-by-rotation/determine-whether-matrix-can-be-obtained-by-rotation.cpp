class Solution {
private:
    void rotate(vector<vector<int>>&v){
        int n=v.size();
        vector<vector<int>> temp(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[j][n-i-1]=v[i][j];
            }
        }
        v=temp;
        return;
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();

        for(int i=0;i<4;i++){
            if(mat==target)return true;
            rotate(mat);
        }
        return false;
    }
};