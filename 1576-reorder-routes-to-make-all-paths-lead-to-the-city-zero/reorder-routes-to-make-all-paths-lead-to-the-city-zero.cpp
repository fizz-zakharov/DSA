class Solution {
private:
    void dfs(int node,vector<vector<int>>&adj,set<vector<int>>&s,int&ans,vector<int>&vis,vector<int>&indegree){
        if(indegree[node]==1 && node!=0)return;
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it])continue;
            if(s.find({it,node})==s.end()){
                ans++;
                cout<<it<<" "<<node<<'\n';
            }
            dfs(it,adj,s,ans,vis,indegree);
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        set<vector<int>> s;
        for(auto it:connections){
            s.insert(it);
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        int ans=0;
        vector<int> vis(n,0);
        dfs(0,adj,s,ans,vis,indegree);
        return ans;

    }
};