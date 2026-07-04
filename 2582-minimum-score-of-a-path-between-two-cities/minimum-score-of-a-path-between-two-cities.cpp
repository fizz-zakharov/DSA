class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> visited(n+1,0);
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        queue<int> q;
        q.push(1);
        visited[0]=1;
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(visited[it.first]){
                    ans.push_back(it.second);
                    continue;
                }
                visited[it.first]=1;
                ans.push_back(it.second);
                q.push(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};