class Solution {
private:
    int fn(int node,vector<vector<int>>&adj,vector<int>&vis,vector<bool>&apple){
        vis[node]=1;
        int time=0;
        for(auto it:adj[node]){
            if(vis[it])continue;
            time+=fn(it,adj,vis,apple);
        }
        if(node!=0 && (apple[node]||time>0))time++;
        return time;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        return 2*fn(0,adj,vis,hasApple);

    }
};