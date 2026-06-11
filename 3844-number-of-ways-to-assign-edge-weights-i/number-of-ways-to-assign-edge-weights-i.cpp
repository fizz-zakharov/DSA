class Solution {
long long MOD=1e9+7;
private:
    void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&temp,vector<int>&path){
        if(adj[node].size()==1 && node!=1){
            if(path.size()<temp.size()){
                path=temp;
            }
            return;
        }
        for(auto it:adj[node]){
            if(it==parent) continue;
            temp.push_back(it);
            dfs(it,node,adj,temp,path);
            temp.pop_back();
        }
    }
    long long exp(long long a,long long b,long long mod){
        long long ans=1;
        a%=mod;

        while(b>0){
            if(b&1){              
                ans=(ans*a)%mod;
            }
            a=(a*a)%mod;
            b>>=1;                  
        }

        return ans;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int m=edges.size();
        vector<vector<int>> adj(m+2);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> path;
        vector<int> temp;
        temp.push_back(1);
        dfs(1,-1,adj,temp,path);
        long long n=path.size();

        long long ans=exp(2,n-2,MOD);
        return ans;
    }
};