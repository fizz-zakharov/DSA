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
    void inorder(TreeNode* node,vector<int>&v){
        if(node==NULL)return;
        if(node->left!=NULL){
            inorder(node->left,v);
        }
        v.push_back(node->val);
        if(node->right!=NULL){
            inorder(node->right,v);
        }
    }

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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        vector<int> v;
        inorder(root,v);
        v.push_back(val);
        TreeNode* rt=new TreeNode(-1);
        fn(0,v.size()-1,rt,v);
        return rt;
    }
};