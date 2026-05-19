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
map<long long,int> m;
private:
    void fn(TreeNode* node,long long sum,int k,int& ans){
        if(node==NULL)return;
        sum+=node->val;
        ans+=m[sum-k];
        m[sum]++;
        if(node->left!=NULL)fn(node->left,sum,k,ans);
        if(node->right!=NULL)fn(node->right,sum,k,ans);
        m[sum]--;
        sum-=node->val;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans=0;
        m[0]=1;
        fn(root,0,targetSum,ans);
        return ans;
    }
};