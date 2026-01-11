class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=low+((high-low)>>1);
            if(target==matrix[mid][0])return true;
            if(target>=matrix[mid][0]&&target<=matrix[mid][n-1]){
                int low2=0,high2=n-1;
                while(low2<=high2){
                    int mid2=low2+((high2-low2)>>1);
                    if(target==matrix[mid][mid2])return true;
                    if(target<matrix[mid][mid2])high2=mid2-1;
                    else low2=mid2+1;
                }
            }
            if(target<matrix[mid][0])high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};