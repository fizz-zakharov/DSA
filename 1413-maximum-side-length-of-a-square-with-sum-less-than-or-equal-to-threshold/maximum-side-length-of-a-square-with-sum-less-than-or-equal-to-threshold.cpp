class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>> precol(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            int sum=0;
            for(int i=0;i<m;i++){
                sum+=mat[i][j];
                precol[i][j]=sum;
            }
        }

        vector<vector<int>> total(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=precol[i][j];
                total[i][j]=sum;
            }
        }
        int ans=0;
        bool check=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int low = ans + 1;
                int high = min(i + 1, j + 1);

                while(low <= high){
                    int mid = (low + high) / 2;

                    int r1 = i - mid + 1;
                    int c1 = j - mid + 1;

                    int sum = total[i][j];
                    if(r1>0)sum-=total[r1-1][j];
                    if(c1>0)sum-=total[i][c1-1];
                    if (r1>0&&c1>0)sum+=total[r1-1][c1-1];
                    if(sum<=threshold){
                        ans = mid;
                        low = mid + 1;
                    } 
                    else high = mid - 1;
                }
            }
        }
        return ans;
    }
};