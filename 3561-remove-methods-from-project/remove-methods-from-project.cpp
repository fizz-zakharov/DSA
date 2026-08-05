/*class DisjointSet{
    vector<int> par,rank;
    DisjointSet(int n){
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)par[i]=i;
    }

    int findultpar(int u){
        if(par[u]==u)return u;
        return par[u]=findultpar(par[u]);
    }
    
    void unionbyrank(int u,int v){
        int ult_pu=findultpar[u];
        int ult_pv=findultpar[v];
        if(ult_pu==ult_pv)return;
        if(rank[ult_pu]>rank[ult_pv]){
            par[ult_pv]=ult_pu;
        }
        else if(rank[ult_pu]<rank[ult_pv]){
            par[ult_pu]=ult_pv;
        }
        else{
            par[ult_pu]=ult_pv;
            rank[ult_pv]++;
        }
    }
};
*/



class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto it:invocations){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        vector<int> sus(n,0);
        vector<int> vis(n,0);
        sus[k]=1;
        queue<int> q;
        q.push(k);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            vis[node]=1;
            sus[node]=1;
            for(auto it:adj[node]){
                if(vis[it])continue;
                q.push(it);
            }
        }
        bool rem=false;
        for(auto it:invocations){
            int u=it[0];
            int v=it[1];
            if(sus[u]==0 && sus[v]==1){
                rem=true;
                break;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(rem){
                ans.push_back(i);
                continue;
            }
            if(sus[i]==0)ans.push_back(i);
        }
        return ans;

    }
};