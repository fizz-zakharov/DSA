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
    int ans=0;
    pair<int,int> postorder(TreeNode* node){
        if(!node)return {0,0};
        pair<int,int> l=postorder(node->left);
        pair<int,int> r=postorder(node->right);
        int sum=l.first+r.first+node->val;
        int c=l.second+r.second+1;
        if(sum/c==node->val)ans++;
        return {sum,c};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        pair<int,int> temp=postorder(root);
        return ans;
    }
};