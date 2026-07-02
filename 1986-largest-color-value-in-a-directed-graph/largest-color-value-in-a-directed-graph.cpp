class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        //detecting a cycle in a DG using topo sort
        queue<int> q;
        vector<vector<int>> colorval(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                colorval[i][colors[i]-'a']=1;
                q.push(i);
            }
        }
        int topo=0;
        int ans=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo++;
            for(int i=0;i<26;i++){
                ans=max(ans,colorval[node][i]);
            }
            for(auto it:adj[node]){
                for(int i=0;i<26;i++){
                    colorval[it][i]=max(colorval[it][i],colorval[node][i]);
                }
                indegree[it]--;
                if(indegree[it]==0){
                    colorval[it][colors[it]-'a']++;
                    q.push(it);
                }
            }
        }
        if(topo!=n)return -1;
        return ans;

    }
};