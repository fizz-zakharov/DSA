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
    void dfs(TreeNode* node,int state,int path,int& ans){
        //state = 1->go right, 2->go left
        if(!node)return;
        ans=max(ans,path);
        if(state==0){
            dfs(node->left,1,path+1,ans);
            dfs(node->right,2,path+1,ans);
        }
        else if(state==1){
            dfs(node->right,2,path+1,ans);
            dfs(node->left,1,1,ans);
        }
        else{
            dfs(node->right,2,1,ans);
            dfs(node->left,1,path+1,ans);
        }
        return;
    }
public:
    int longestZigZag(TreeNode* root) {
        int ans=0;
        dfs(root,0,0,ans);
        return ans;
    }
};