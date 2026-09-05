class Solution {
private:
    int n1;
    const int col=18;
    vector<vector<pair<int,int>>> adj;
    vector<vector<int>> freq;
    vector<vector<int>> dp;
    vector<int> depth;
    vector<int> vis;

    void dfs(int node,int par,int d){
        if(vis[node])return;
        vis[node]=1;
        depth[node]=d;
        dp[node][0]=(par!=-1)?par:node;
        for(auto it:adj[node]){
            int v=it.first;
            int w=it.second;
            if(vis[v])continue;
            for(int i=1;i<=26;i++){
                freq[v][i]=freq[node][i];
            }
            freq[v][w]+=1;
            dfs(v,node,d+1);
        }
        return;
    }

    int lca(int a,int b){
        if(depth[a]<depth[b]) swap(a,b);
        int diff = depth[a]-depth[b];
        for(int j=0;j<col;j++){
            if((diff>>j)&1) a=dp[a][j];
        }
        if(a==b)return a;

        for(int j=col-1;j>=0;j--){
            if(dp[a][j]!=dp[b][j]){
                a=dp[a][j];
                b=dp[b][j];
            }
        }
        return dp[a][0];
    }
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        adj.resize(n);
        freq.resize(n,vector<int>(27,0));
        dp.resize(n,vector<int>(col,0));
        depth.resize(n,0);
        vis.resize(n,0);
        for(auto& it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dfs(0,-1,0);
        for(int j=1;j<col;j++){
            for(int node=0;node<n;node++){
                int mid=dp[node][j-1];
                dp[node][j]=dp[mid][j-1];
            }
        }
        vector<int> ans(queries.size(),0);
        int j=0;
        for(auto it:queries){
            int u=it[0];
            int v=it[1];
            int up=lca(u,v);
            int mx=0;
            int tot=0;
            for(int i=1;i<=26;i++){
                int c=(freq[u][i]-freq[up][i])+(freq[v][i]-freq[up][i]);
                
                tot+=c;
                mx=max(mx,c);
                
            }
            ans[j] = tot-mx;
            j++;
        }
        return ans;
    }
};