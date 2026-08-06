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
    int minchild(TreeNode* node,int& ans){
        if(!node)return -1;

        int l=minchild(node->left,ans);
        int r=minchild(node->right,ans);

        int val;
        if(l==-1 && r==-1)val=node->val;
        else if(l==-1)val=r;
        else if(r==-1)val=l;
        else val=min(l,r);
        ans = max(ans, abs(node->val - val));
        return min(node->val, val);
    }
    int maxchild(TreeNode* node,int& ans){
        if(!node)return -1;

        int l=maxchild(node->left,ans);
        int r=maxchild(node->right,ans);

        int val;
        if(l==-1 && r==-1)val=node->val;
        else if(l==-1)val=r;
        else if(r==-1)val=l;
        else val=max(l,r);
        ans = max(ans, abs(node->val - val));
        return max(node->val, val);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans=-1;
        int a=minchild(root,ans);
        int b=maxchild(root,ans);
        return ans;
    }
};