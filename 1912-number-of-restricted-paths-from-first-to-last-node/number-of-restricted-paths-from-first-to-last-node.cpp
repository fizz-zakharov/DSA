class Solution {
long long MOD=1e9+7;
private:
    int dp[20002];
    int dfs(int node,vector<vector<pair<int,int>>>&adj,vector<int>&vis,vector<int>&dist,int n){
        if(node==n){
            return 1;
        }
        if(dp[node]!=-1)return dp[node];
        int a=0;
        for(auto it:adj[node]){
            if(vis[it.first]==0 && dist[it.first]<dist[node]){
                vis[it.first]=1;
                a=(a+dfs(it.first,adj,vis,dist,n))%MOD;
                vis[it.first]=0;
            }
        }
        return dp[node] = a;
    }
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,n});
        vector<int> dist(n+1,INT_MAX);
        vector<int> visited(n+1,0);
        dist[n]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            if(dist[node]!=dis)continue;
            for(auto it: adj[node]){
                int adjnode=it.first;
                int w=it.second;
                if(dist[node]+w<dist[adjnode]){
                    dist[adjnode]=dist[node]+w;
                    pq.push({dist[node]+w,adjnode});
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        visited.resize(n+1,0);
        return dfs(1,adj,visited,dist,n);

    }
};