class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int target=(1<<n)-1;

        vector<vector<int>> dp(n,vector<int>(1<<n,INT_MAX));
        queue<pair<int,pair<int,int>>> q; //{dist,{node,mask}}
        for(int i=0;i<n;i++){
            q.push({0,{i,1<<i}});
            dp[i][1<<i]=0;
        }
        while(!q.empty()){
            int dist=q.front().first;
            int node=q.front().second.first;
            int mask=q.front().second.second;
            q.pop();
            if(dp[node][mask]!=dist)continue;
            for(auto it:graph[node]){
                int newmask=(mask|(1<<it));
                if(1+dp[node][mask]<dp[it][newmask]){
                    dp[it][newmask]=1+dp[node][mask];
                    q.push({1+dist,{it,newmask}});
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[i][target]);
        }
        return ans;
    }
};