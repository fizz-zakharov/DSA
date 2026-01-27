class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w,1});
            adj[v].push_back({u,w,0});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dis(n,1e9);
        pq.push({0,0});
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjnode=it[0];
                int edgeweight=(it[2])?it[1]:2*it[1];
                if(dist+edgeweight<dis[adjnode]){
                    dis[adjnode]=dist+edgeweight;
                    pq.push({dist+edgeweight,adjnode});
                }
            }
        }
        return (dis[n-1]==1e9)?-1:dis[n-1];
    }
};