class Solution {
private:
    vector<vector<pair<int,int>>> adj;
    vector<int> indegree;
    vector<long long> minpathcost;

    bool valid(int m,int n,vector<vector<int>>&ed,vector<bool>&online,long long k){
        for(int i=0;i<n;i++){
            adj[i].clear();
            indegree[i]=0;
            minpathcost[i]=LLONG_MAX;
        }

        for(auto& it:ed){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            if(w>=m && online[u] && online[v]){
                adj[u].push_back({v,w});
                indegree[v]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);
        minpathcost[0]=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            long long current_dist=minpathcost[node];
            for(auto& it:adj[node]){
                int adjnode=it.first;
                int wt=it.second;
                if(current_dist != LLONG_MAX && current_dist+wt<minpathcost[adjnode]){
                    minpathcost[adjnode]=current_dist+wt;
                }
                if(--indegree[adjnode]==0) q.push(adjnode);
            }
        }
        return minpathcost[n-1]<=k;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        adj.assign(n,{});
        indegree.assign(n,0);
        minpathcost.assign(n,LLONG_MAX);

        int low=0,high=1e9;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(valid(mid,n,edges,online,k)){
                ans=mid;
                low=mid+1;
            } else {
                high=mid-1;
            }
        }
        return ans;
    }
};