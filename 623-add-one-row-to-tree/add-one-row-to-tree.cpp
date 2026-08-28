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
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newroot=new TreeNode(val);
            if(root==NULL)return newroot;
            newroot->left=root;
            return newroot;
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int d=q.front().second;
            q.pop();
            if(d==depth-1){
                TreeNode* addleft=new TreeNode(val);
                TreeNode* addright=new TreeNode(val);
                if(node->left!=NULL){
                    TreeNode* templeft=node->left;
                    node->left=addleft;
                    addleft->left=templeft;
                }
                else{
                    node->left=addleft;
                }
                if(node->right!=NULL){
                    TreeNode* tempright=node->right;
                    node->right=addright;
                    addright->right=tempright;
                }
                else{
                    node->right=addright;
                }
            }
            if(node->left!=NULL)q.push({node->left,d+1});
            if(node->right!=NULL)q.push({node->right,d+1});
        }
        return root;
    }
};