class TreeAncestor {
public:
    vector<vector<int>> dp;
    int col;
    TreeAncestor(int n, vector<int>& parent) {
        dp.resize(n,vector<int>(log2(n)+1,-1));
        for(int i=1;i<n;i++)dp[i][0]=parent[i];
        col=log2(n)+1;
        for(int j=1;j<col;j++){
            for(int node=0;node<n;node++){
                if(dp[node][j-1]!=-1)dp[node][j]=dp[dp[node][j-1]][j-1];
            }
        }
    }

    
    int getKthAncestor(int node, int k) {
        for(int j=0;j<col;j++){
            if(k&(1<<j)){
                node=dp[node][j];
                if(node==-1)return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */