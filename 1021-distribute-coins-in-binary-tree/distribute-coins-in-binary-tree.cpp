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
    int fn(TreeNode* node,int& ans){
        if(node==NULL)return 0;
        int l=fn(node->left,ans);
        int r=fn(node->right,ans);
        ans+=abs(l)+abs(r);
        return (l+r+node->val)-1;
    }
public:
    int distributeCoins(TreeNode* root) {
        int ans=0;
        fn(root,ans);
        return ans;
    }
};