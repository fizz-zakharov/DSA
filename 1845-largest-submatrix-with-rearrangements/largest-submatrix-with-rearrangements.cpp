class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>> precol(m,vector<int> (n,0));
        for(int j=0;j<n;j++){
            int sum=0;
            for(int i=0;i<m;i++){
                sum+=matrix[i][j];
                if(matrix[i][j]==0)sum=0;
                precol[i][j]=sum;
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<m;i++){
            sort(precol[i].begin(),precol[i].end());
            for(int j=0;j<n;j++){
                ans=max(ans,precol[i][j]*(n-j));
            }
        }
        return ans;
    }
};