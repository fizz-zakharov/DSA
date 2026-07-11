class Solution {
private:
    int fn(int node,vector<vector<int>>&adj,vector<int>& vis){
        queue<int> q;
        q.push(node);
        int ms=0;
        vis[node]=1;
        unordered_map<int,int> m;
        int c=0;
        while(!q.empty()){
            int el=q.front();
            q.pop();
            int val=adj[el].size();
            ms=max(ms,val);
            m[adj[el].size()]++;
            c++;
            for(auto it:adj[el]){
                if(vis[it]!=1){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        cout<<c<<'\n';
        cout<<ms<<'\n';
        cout<<m[ms]<<'\n';
        return (m[ms]==c && ms==c-1);
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans+=fn(i,adj,vis);
            }
        }
        return ans;

    }
};