class Solution {
private:
    int n;
    const int MOD=1e9+7;
    const int col=20;
    vector<vector<int>> adj;
    vector<int> vis;
    vector<int> depth;
    vector<vector<int>> dp;
    
    void fn(int node,int par,int d){
        if(vis[node])return;
        vis[node]=1;
        dp[node][0]=(par!=-1)?par:node;
        for(int j=1;j<col;j++){
            dp[node][j]=dp[dp[node][j-1]][j-1];
        }
        depth[node]=d;
        for(auto it:adj[node]){
            if(vis[it])continue;
            fn(it,node,d+1);
        }
        return;
    }

    int lca(int a,int b){
        if(depth[a]<depth[b])swap(a,b);
        int diff=depth[a]-depth[b];
        for(int j=0;j<col;j++){
            if((diff>>j)&1){
                a=dp[a][j];
            }
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

    long long binexp(long long a,int x){
        if(x<0)return 0;
        long long ans=1;
        a%=MOD;
        while(x>0){
            if(x&1)ans=(ans*a)%MOD;
            a=(a*a)%MOD;
            x>>=1;
        }
        return ans;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int q=queries.size();
        if(edges.empty()) return vector<int>(q, 0);

        n=edges.size()+1;
        adj.assign(n+1, vector<int>());
        vis.assign(n+1, 0);
        depth.assign(n+1, 0);
        dp.assign(n+1, vector<int>(col, 0));

        for(auto& it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        fn(edges[0][0],-1,0);

        vector<int> ans(q);
        int i=0;
        while(q--){
            int u=queries[i][0];
            int v=queries[i][1];

            int l=lca(u,v);
            int c=depth[u]+depth[v]-2*depth[l];
            int cur=(c==0)?0:binexp(2,c-1);
            ans[i]=cur;
            i++;
        }
        return ans;
    }
};