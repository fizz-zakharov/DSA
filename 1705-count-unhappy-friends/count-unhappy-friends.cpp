class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int ans=0;
        unordered_map<int,int> m;
        vector<vector<int>> rank(n,vector<int>(n,0));
        for(auto it:pairs){
            int u=it[0];
            int v=it[1];
            m[u]=v;
            m[v]=u;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                rank[i][preferences[i][j]]=j;
            }
        }

        for(int x=0;x<n;x++){
            int y=m[x];
            for(int i=0;i<n;i++){
                if(i==x || i==y)continue;
                if(rank[x][i]<rank[x][y] && rank[i][x]<rank[i][m[i]]){
                    ans++;
                    break;
                }
            }
        }
        return ans;

    }
};