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
    pair<int,pair<int,pair<int,int>>> fn(TreeNode* node){ //{sum,{isBST,{max,min}}}
        if(!node)return {0,{1,{-1e5,1e5}}};
        pair<int,pair<int,pair<int,int>>> l=fn(node->left);
        pair<int,pair<int,pair<int,int>>> r=fn(node->right);
        int sum=l.first+r.first+node->val;
        int isBST=(l.second.first && r.second.first && node->val>l.second.second.first && node->val<r.second.second.second)?1:0;
        int mx=max(node->val,r.second.second.first);
        int mn=min(node->val,l.second.second.second);
        if(isBST)ans=max(ans,sum);
        return {sum,{isBST,{mx,mn}}};
    }
public:
    int maxSumBST(TreeNode* root) {
        pair<int,pair<int,pair<int,int>>> temp=fn(root);
        return ans;
    }
};