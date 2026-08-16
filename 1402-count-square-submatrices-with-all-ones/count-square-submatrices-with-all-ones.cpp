class Solution {
private:
    vector<vector<int>> pre;
    bool valid(int x1,int y1,int x2,int y2,int k){
        int sum=pre[x2+1][y2+1]-pre[x1][y2+1]-pre[x2+1][y1]+pre[x1][y1];
        return (k*k==sum);
    }

    int fn(int i,int j,int m,int n){
        int low=0,high=min(m-i,n-j);
        int c=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(valid(i,j,i+mid-1,j+mid-1,mid)){
                c=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return c;
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        pre.resize(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pre[i+1][j+1]=matrix[i][j]+pre[i+1][j]+pre[i][j+1]-pre[i][j];
            }
        }
        /*
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<pre[i][j]<<" ";
            }
            cout<<'\n';
        }
        */
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans+=fn(i,j,m,n);
            }
        }


        return ans;

    }

};