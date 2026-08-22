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
    int dfs(TreeNode* node){
        if(!node)return 0;
        int a=dfs(node->left);
        int b=dfs(node->right);
        bool ch=false;
        if(a==0){
            node->left=NULL;
        }
        if(b==0){
            node->right=NULL;
        }
        if(node->val==1)return 1;
        return (a||b);
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        int x=dfs(root);
        if(x==0)return NULL;
        return root;
    }
};