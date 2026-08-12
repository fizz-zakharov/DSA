class Solution {
private:
    vector<int> fn(int node,vector<vector<int>>&adj,vector<int>&vis,string& s,int n,vector<int>&ans){
        vis[node]=1;
        vector<int> freq(26,0);
        vector<int> a;
        for(auto it:adj[node]){
            if(vis[it])continue;
            a=fn(it,adj,vis,s,n,ans);
            for(int i=0;i<26;i++){
                freq[i]+=a[i];
            }
        }
        freq[s[node]-'a']++;
        ans[node]=freq[s[node]-'a'];
        return freq;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        vector<int> ans(n,0);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        vector<int> temp=fn(0,adj,vis,labels,n,ans);
        return ans;
    }
};