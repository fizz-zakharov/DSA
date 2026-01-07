class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        long long low=INT_MAX;
        int c=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0)c++;
                if(abs(matrix[i][j])<low)low=abs(matrix[i][j]);
                ans+=abs(matrix[i][j]);
            }
        }
        if(c&1)return ans-(2*low);
        return ans;
    }
};