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
    void fn(int i,TreeNode* node,vector<int>& post,vector<int>& in,unordered_map<int,int>&m,int l,int r){
        if(i>=post.size())return;
        
        for(int j=i+1;j<post.size();j++){
            if(m[post[j]]>m[node->val] && m[post[j]]<=r){
                TreeNode* next=new TreeNode(post[j]);
                node->right=next;
                fn(j,next,post,in,m,m[node->val]+1,r);
                break;
            }
        }
        for(int j=i+1;j<post.size();j++){
            if(m[post[j]]<m[node->val] && m[post[j]]>=l){
                TreeNode* next=new TreeNode(post[j]);
                node->left=next;
                fn(j,next,post,in,m,l,m[node->val]-1);
                break;
            }
        }
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        reverse(postorder.begin(),postorder.end());
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)m[inorder[i]]=i;
        TreeNode* root=new TreeNode(postorder[0]);
        fn(0,root,postorder,inorder,m,0,n-1);
        return root;
    }
};