class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int c=0;
        vector<int> prerow(m);
        vector<int> precol(n);
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=mat[i][j];
            }
            prerow[i]=sum;
        }
        for(int j=0;j<n;j++){
            int sum=0;
            for(int i=0;i<m;i++){
                sum+=mat[i][j];
            }
            precol[j]=sum;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]&&prerow[i]==1&&precol[j]==1)c++;
            }
        }
        return c;
    }
};