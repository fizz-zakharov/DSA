class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1);
        for(auto it:relations){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int> maxtime(n+1,0);
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0)q.push(i);
            maxtime[i]=time[i-1];
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                maxtime[it]=max(maxtime[it],maxtime[node]+time[it-1]);
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            ans=max(ans,maxtime[i]);
        }
        return ans;
    }
};