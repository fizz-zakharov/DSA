class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n=receiver.size();
        const int col=34;
        vector<vector<int>> parent(n,vector<int>(col,0));
        vector<vector<long long>> sum(n,vector<long long>(col,0));
        for(int i=0;i<n;i++){
            parent[i][0]=receiver[i];
            sum[i][0]=receiver[i];
        }

        for(int j=1;j<col;j++){
            for(int i=0;i<n;i++){
                parent[i][j]=parent[parent[i][j-1]][j-1];
                sum[i][j]=sum[i][j-1] + sum[parent[i][j-1]][j-1];
            }
        }
        long long ans=LLONG_MIN;

        for(int i=0;i<n;i++){
            int x=i;
            long long score=i;
            for(int j=0;j<col;j++){
                if((1LL<<j)&k){
                    score+=sum[x][j];
                    x=parent[x][j];
                }
            }
            ans=max(ans,score);
        }
        return ans;
        

    }
};