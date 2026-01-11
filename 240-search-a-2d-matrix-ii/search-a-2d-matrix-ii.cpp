class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            if(target>=matrix[i][0]&&target<=matrix[i][n-1]){
                int low=0,high=n-1;
                while(low<=high){
                    int mid=low+(high-low)/2;
                    if(target==matrix[i][mid])return true;
                    if(target<matrix[i][mid])high=mid-1;
                    else low=mid+1;
                }
            }
        }
        return false;
        
    }
};