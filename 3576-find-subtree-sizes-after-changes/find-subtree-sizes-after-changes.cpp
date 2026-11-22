class Solution {
private:
    int n;
    vector<vector<int>> ans;
    vector<int> finalans;
    void dfs(int node,int par,vector<vector<int>>&adj,string& s,vector<int>&rec){
        if(rec[s[node]-'a']!=-1){
            ans[rec[s[node]-'a']].push_back(node);
        }
        else if(par!=-1) ans[par].push_back(node);
        int temp=rec[s[node]-'a'];
        rec[s[node]-'a']=node;
        for(auto it:adj[node]){
            dfs(it,node,adj,s,rec);
        }
        rec[s[node]-'a']=temp;
        return;
    }

    int dfs2(int node,vector<vector<int>>&adj){
        if(adj[node].size()==0)return finalans[node]=1;
        int res=0;
        for(auto it:adj[node]){
            res+=dfs2(it,adj);
        }
        return finalans[node]=1+res;
    }

public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        n=parent.size();
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        vector<int> rec(26,-1);
        ans.resize(n);
        dfs(0,-1,adj,s,rec);
        finalans.resize(n,0);
        dfs2(0,ans);
        return finalans;
    }
};