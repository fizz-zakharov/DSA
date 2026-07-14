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
    void fn(int i,TreeNode* node,vector<int>&v,vector<int>&vis){
        if(i>=v.size())return;
        bool lch=true;
        int lind=-1;
        int rind=-1;
        for(int j=i+1;j<v.size();j++){
            if(v[j]<node->val && lch){
                TreeNode* l=new TreeNode(v[j]);
                node->left=l;
                vis[v[j]]=1;
                lind=j;
                lch=false;
            }
            if(v[j]>node->val){
                if(vis[v[j]])break;
                TreeNode* r=new TreeNode(v[j]);
                node->right=r;
                vis[v[j]]=1;
                rind=j;
                break;
            }
        }
        if(lind!=-1)fn(lind,node->left,v,vis);
        if(rind!=-1)fn(rind,node->right,v,vis);
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode(preorder[0]);
        vector<int> vis(1001,0);
        fn(0,root,preorder,vis);
        return root;
    }
};