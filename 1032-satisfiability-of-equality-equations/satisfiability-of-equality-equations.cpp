class DisjointSet{
    vector<int> parent,size,rank;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,0);
        for(int i=0;i<n;i++)parent[i]=i;
    }

    int findultparent(int node){
        if(parent[node]==node)return node;
        return parent[node]=findultparent(parent[node]); //uses path compression
    }

    void unionbyrank(int a,int b){
        int ulp_a=findultparent(a);
        int ulp_b=findultparent(b);
        if(ulp_a==ulp_b)return;
        if(rank[ulp_a]>rank[ulp_b]){
            parent[ulp_b]=ulp_a;
        }
        else if(rank[ulp_b]>rank[ulp_a]){
            parent[ulp_a]=ulp_b;
        }
        else{
            parent[ulp_a]=ulp_b;
            rank[b]++;
        }
    }
};



class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DisjointSet dsu(26);
        for(auto it:equations){
            if(it[1]=='='){
                int a=it[0]-'a';
                int b=it[3]-'a';
                dsu.unionbyrank(a,b);
            }
        }
        for(auto it:equations){
            if(it[1]=='!' && dsu.findultparent(it[0]-'a')==dsu.findultparent(it[3]-'a')){
                return false;
            }
        }
        return true;
    }
};