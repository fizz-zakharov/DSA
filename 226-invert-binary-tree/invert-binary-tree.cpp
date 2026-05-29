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
    void fn(TreeNode* node){
        if(node->left==NULL && node->right==NULL){
            return;
        }
        TreeNode* temp;
        if(node->left!=NULL){
            temp=node->left;
            if(node->right!=NULL){
                node->left=node->right;
                node->right=temp;
            }
            else{
                node->left=NULL;
                node->right=temp;
            }
        }
        else{
            temp=node->right;
            node->left=temp;
            node->right=NULL;
        }
        if(node->left!=NULL)fn(node->left);
        if(node->right!=NULL)fn(node->right);
        return;
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return NULL;
        fn(root);
        return root;
    }
};