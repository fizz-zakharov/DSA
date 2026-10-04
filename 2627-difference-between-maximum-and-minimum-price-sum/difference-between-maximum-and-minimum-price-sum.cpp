class Solution {
public:
    vector<vector<int>>adj;
    vector<int>nums;
    vector<long long>down;
    vector<long long>up;
    void dfs1(int node,int par){
        down[node] = 0;
        for(auto child : adj[node]){
            if(child == par) continue;
            dfs1(child,node);
            down[node] = max(down[node],nums[child]+down[child]);
        }
    }
    void dfs2(int node,int par){
        long long best1 = 0, best2 = 0;
        long long bestChild;
        for(auto child : adj[node]){
            if(child == par) continue;
            if(child)
            if(nums[child]+down[child]>best1){
                best2 = best1;
                best1 = nums[child]+down[child];
                bestChild = child;
            }
            else if(nums[child]+down[child]>best2){
                best2 = nums[child]+down[child];
            }
        }

        for(auto child : adj[node]){
            if(child == par) continue;

            long long bestFromSibling;
            if(child == bestChild){
                bestFromSibling = best2;
            }
            else{
                bestFromSibling = best1;
            }

            up[child] = nums[node] + max(bestFromSibling,up[node]);

            dfs2(child,node);
        }
    }
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        adj.assign(n,{});
        down.assign(n,0);
        up.assign(n,0);
        for(auto it : edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        nums = price;
        dfs1(0,-1);
        // test(down)
        dfs2(0,-1);
        // test(up)
        long long ans = 0;
        for(int i = 0;i<n;i++){
            ans = max({ans,down[i],up[i]});
        }
        return ans;
    }
};