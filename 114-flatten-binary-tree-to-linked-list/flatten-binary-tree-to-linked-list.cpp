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
    void fn(TreeNode* node,TreeNode* &prev){
        if(node==NULL)return;
        fn(node->right,prev);
        fn(node->left,prev);
        node->left=NULL;
        node->right=prev;
        prev=node;
    }
public:
    void flatten(TreeNode* root) {
        TreeNode* prev=NULL;
        fn(root,prev);
    }
};