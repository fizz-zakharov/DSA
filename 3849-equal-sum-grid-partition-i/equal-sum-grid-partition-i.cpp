class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long m=grid.size();
        long long n=grid[0].size();
        vector<long long> prerow(n),suffrow(n);
        vector<long long> precol(m),suffcol(m);



        //row
        for(long long j=0;j<n;j++){
            long long prefix=0;
            for(long long i=0;i<m;i++){
                prefix+=grid[i][j];
            }
            prerow[j]=prefix;
        }
        long long sum=0;
        for(long long i=0;i<n;i++){
            sum+=prerow[i];
            prerow[i]=sum;
        }
        suffrow[n-1]=0;
        for(long long j=n-1;j>=0;j--){
            long long suffix=0;
            for(long long i=0;i<m;i++){
                suffix+=grid[i][j];
            }
            if(j>0)suffrow[j-1]=suffix;
        }
        sum=0;
        for(long long i=n-1;i>=0;i--){
            sum+=suffrow[i];
            suffrow[i]=sum;
        }


        //column
        for(long long i=0;i<m;i++){
            long long prefix=0;
            for(long long j=0;j<n;j++){
                prefix+=grid[i][j];
            }
            precol[i]=prefix;
        }
        sum=0;
        for(long long i=0;i<m;i++){
            sum+=precol[i];
            precol[i]=sum;
        }
        suffcol[m-1]=0;
        for(long long i=m-1;i>=0;i--){
            long long suffix=0;
            for(long long j=0;j<n;j++){
                suffix+=grid[i][j];
            }
            if(i>0)suffcol[i-1]=suffix;
        }
        sum=0;
        for(long long i=m-1;i>=0;i--){
            sum+=suffcol[i];
            suffcol[i]=sum;
        }

        for(long long i=0;i<m;i++){
            if(precol[i]==suffcol[i])return true;
        }
        for(long long i=0;i<n;i++){
            if(prerow[i]==suffrow[i])return true;
        }
        return false;


    }
};