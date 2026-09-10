class Solution {
private:
    vector<int> sub;
    vector<int> dp;
    vector<vector<int>> adj;
    int root_ans=0;

    int dfs1(int node,int parent,int h){
        int size=0;
        for(auto it:adj[node]){
            if(it==parent)continue;
            size+=dfs1(it,node,h+1);
        }
        root_ans+=h;
        return sub[node]=1+size;
    }

    void dfs2(int node,int parent,int n){
        for(auto it:adj[node]){
            if(it==parent)continue;
            dp[it]=dp[node]-sub[it]+(n-sub[it]);
            dfs2(it,node,n);
        }
        return;
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        sub.resize(n,0);
        dp.resize(n,0);
        adj.resize(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int temp=dfs1(0,-1,0);
        dp[0]=root_ans;
        dfs2(0,-1,n);
        return dp;
    }
};