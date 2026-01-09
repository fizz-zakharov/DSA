/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* node,int& level,int cur){
        level=max(level,cur);
        if(node->left==NULL&&node->right==NULL)return;
        if(node->left!=NULL)dfs(node->left,level,cur+1);
        if(node->right!=NULL)dfs(node->right,level,cur+1);
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int deepest=1;
        dfs(root,deepest,1);
        vector<int> parent(500,-1);
        vector<int> deep;
        queue<pair<TreeNode*,int>> q;
        unordered_map<int,TreeNode*> m;
        q.push({root,1});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int level=q.front().second;
            q.pop();
            m[node->val]=node;
            if(level==deepest)deep.push_back(node->val);
            if(node->left!=NULL){
                parent[node->left->val]=node->val;
                q.push({node->left,level+1});
            }
            if(node->right!=NULL){
                parent[node->right->val]=node->val;
                q.push({node->right,level+1});
            }
        }
        if(deep.size()==1){
            return m[deep[0]];
        }
        int k=deep.size();
        while(parent[deep[0]]!=parent[deep[k-1]]){
            deep[0]=parent[deep[0]];
            deep[k-1]=parent[deep[k-1]];
        }
        return m[parent[deep[0]]];



    }
};