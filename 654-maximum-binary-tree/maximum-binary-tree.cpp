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
    void fn(int i,int j,TreeNode* node,vector<int>&v){
        if(i==j){
            node->val=v[i];
            return;
        }
        int mx=INT_MIN;
        int ind=-1;
        for(int ptr=i;ptr<=j;ptr++){
            if(v[ptr]>mx){
                mx=v[ptr];
                ind=ptr;
            }
        }
        node->val=mx;
        if(ind-1>=i){
            TreeNode* l=new TreeNode(-1);
            node->left=l;
            fn(i,ind-1,node->left,v);
        }
        if(ind+1<=j){
            TreeNode* r=new TreeNode(-1);
            node->right=r;
            fn(ind+1,j,node->right,v);
        }
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        TreeNode* root=new TreeNode(-1);
        fn(0,n-1,root,nums);
        return root;
    }
};