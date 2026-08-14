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
    pair<int,int> fn(TreeNode* node){
        //pair<int,int> -> <pick current node,dont pick> 
        if(!node)return {0,0};
        pair<int,int> left=fn(node->left);
        pair<int,int> right=fn(node->right);
        int x=node->val+left.second+right.second;
        int y=max(left.first,left.second)+max(right.first,right.second);
        return {x,y};

    }
public:
    int rob(TreeNode* root) {
        pair<int,int> p=fn(root);
        return max(p.first,p.second);
    }
};