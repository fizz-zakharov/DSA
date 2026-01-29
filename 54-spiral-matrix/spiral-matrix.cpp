class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> v;
        int c=m*n;
        int i=0,j=0;
        int rb=n-1,ub=1,db=m-1,lb=0;
        while(c){
            while(j<=rb&&c){
                v.push_back(matrix[i][j]);
                j++;
                c--;
            }
            j--;
            i++;
            rb--;
            while(i<=db&&c){
                v.push_back(matrix[i][j]);
                i++;
                c--;
            }
            i--;
            j--;
            db--;
            while(j>=lb&&c){
                v.push_back(matrix[i][j]);
                j--;
                c--;
            }
            j++;
            i--;
            lb++;

            while(i>=ub&&c){
                v.push_back(matrix[i][j]);
                i--;
                c--;
            }
            i++;
            j++;
            ub++;
        }
        return v;
        
    }
};