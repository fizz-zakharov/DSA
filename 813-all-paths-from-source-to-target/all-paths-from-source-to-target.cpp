class Solution {
private:
    void fn(int node,vector<vector<int>>&adj,vector<vector<int>>&ans,vector<int>&temp,int n){
        if(node==n-1){
            ans.push_back(temp);
            return;
        }
        for(auto it:adj[node]){
            temp.push_back(it);
            fn(it,adj,ans,temp,n);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(0);
        fn(0,graph,ans,temp,n);
        return ans;
    }
};