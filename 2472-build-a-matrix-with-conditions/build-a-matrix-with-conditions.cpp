class Solution {
private:
    vector<int> toposort(int k,vector<vector<int>>&v){
        vector<vector<int>> adj(k+1);
        vector<int> indegrees(k+1,0);
        for(auto it:v){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegrees[v]++;
        }
        queue<int> q;
        for(int i=1;i<=k;i++){
            if(indegrees[i]==0)q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegrees[it]--;
                if(indegrees[it]==0)q.push(it);
            }
        }
        return ans;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans;
        vector<int> toporow=toposort(k,rowConditions);
        vector<int> topocol=toposort(k,colConditions);
        if(toporow.size()!=k||topocol.size()!=k)return ans;

        ans.resize(k,vector<int>(k,0));
        vector<int> maprow(k+1);
        vector<int> mapcol(k+1);
        for(int i=0;i<k;i++)maprow[toporow[i]]=i;
        for(int i=0;i<k;i++)mapcol[topocol[i]]=i;

        for(int i=1;i<=k;i++){
            ans[maprow[i]][mapcol[i]]=i;
        }
        return ans;
    }
};