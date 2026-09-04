/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<TreeNode*,vector<TreeNode*>> dp;
    map<TreeNode*,int> depth;
    const int col=32;
    void dfs(TreeNode* node,TreeNode* par,int d){
        if(!node)return;
        depth[node]=d;
        dp[node].assign(col,NULL);
        if(par!=NULL){
            dp[node][0]=par;
        }
        dfs(node->left,node,d+1);
        dfs(node->right,node,d+1);
        return;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode*,int> depth_of_node;
        dfs(root,NULL,0);
        while(depth[p]>depth[q]){
            p=dp[p][0];
        }
        while(depth[q]>depth[p]){
            q=dp[q][0];
        }
        for(int j=1;j<col;j++){
            for(auto& it:dp){
                TreeNode* node=it.first;
                TreeNode* mid=dp[node][j-1];
                dp[node][j]=mid?dp[mid][j-1]:node;
            }
        }
        if(p==q)return p;
        for(int j=col-1;j>=0;j--){
            if(dp[p][j]!=dp[q][j]){
                p=dp[p][j];
                q=dp[q][j];
            }
        }
        return dp[p][0];
    }   
};