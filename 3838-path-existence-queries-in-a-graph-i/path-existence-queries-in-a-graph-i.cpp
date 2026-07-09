class disjointset{
    vector<int> parent,rank,size;
public:
    disjointset(int n){
        parent.resize(n);
        rank.resize(n,0);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findultpar(int node){
        if(parent[node]==node)return node;
        return parent[node] = findultpar(parent[node]);
    }

    void unionbyrank(int u,int v){
        int ultpar_u=findultpar(u);
        int ultpar_v=findultpar(v);
        if(ultpar_u==ultpar_v)return;
        if(rank[ultpar_u]<rank[ultpar_v]){
            parent[ultpar_u]=ultpar_v;
        }
        else if(rank[ultpar_u]>rank[ultpar_v]){
            parent[ultpar_v]=ultpar_u;
        }
        else{
            parent[ultpar_u]=ultpar_v;
            rank[ultpar_v]++;
        }
    }
};



class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        disjointset dsu(n);
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff){
                dsu.unionbyrank(i,i-1);
            }
        }
        vector<bool> ans;
        for(auto it:queries){
            int u=it[0];
            int v=it[1];
            if(dsu.findultpar(u)==dsu.findultpar(v)){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};