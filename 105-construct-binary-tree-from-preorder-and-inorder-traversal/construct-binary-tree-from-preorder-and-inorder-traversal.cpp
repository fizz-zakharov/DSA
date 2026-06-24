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
    void fn(int i,TreeNode* node,vector<int>& pre,vector<int>& in,map<int,int>&m,int l,int r){
        if(i>=pre.size())return;

        for(int j=i+1;j<pre.size();j++){
            if(m[pre[j]]<m[node->val] && m[pre[j]]>=l){
                TreeNode* next=new TreeNode(pre[j]);
                node->left=next;
                fn(j,next,pre,in,m,l,m[node->val]-1);
                break;
            }
        }
        for(int j=i+1;j<pre.size();j++){
            if(m[pre[j]]>m[node->val] && m[pre[j]]<=r){
                TreeNode* next=new TreeNode(pre[j]);
                node->right=next;
                fn(j,next,pre,in,m,m[node->val]+1,r);
                break;
            }
        }
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        map<int,int> m;
        for(int i=0;i<n;i++)m[inorder[i]]=i;
        TreeNode* root=new TreeNode(preorder[0]);
        fn(0,root,preorder,inorder,m,0,n-1);
        return root;
    }
};