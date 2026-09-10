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
    bool n=false;
    map<TreeNode*,int> sub;
    int dfs1(TreeNode* node){
        if(!node)return 0;
        int a=dfs1(node->left);
        int b=dfs1(node->right);
        int x=0;
        if(!(node->left==NULL && node->right==NULL)){
            if(node->left==NULL){
                x=b;
            }
            else if(node->right==NULL){
                x=a;
            }
            else x=max(a,b);
        }
        return sub[node]=x+node->val;
    }

    void dfs2(TreeNode* node,TreeNode* parent,int sum,int limit){
        if(!node)return;
        if(sum+sub[node]<limit){
            if(parent==NULL){
                n=true;
                return;
            }
            if(parent->left==node){
                parent->left=NULL;
            }
            else{
                parent->right=NULL;
            }
            return;
        }
        dfs2(node->left,node,sum+node->val,limit);
        dfs2(node->right,node,sum+node->val,limit);
        return;
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        dfs1(root);
        dfs2(root,NULL,0,limit);
        if(n)return NULL;
        return root;
    }
};