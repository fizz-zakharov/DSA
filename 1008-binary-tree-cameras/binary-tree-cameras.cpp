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
    int fn(TreeNode* node,TreeNode* root,int& ans){
        if(!node)return 1;
        if(node->left==NULL && node->right==NULL){
            return -1;
        }
        int a=fn(node->left,root,ans);
        int b=fn(node->right,root,ans);
        if(a==-1 || b==-1){
            ans++;
            return 0;
        }
        else if(a==0 || b==0){
            return 1;
        }
        else{
            //if(node==root)ans++;
            return -1;
        }

    }
public:
    int minCameraCover(TreeNode* root) {
        int ans=0;
        int x=fn(root,root,ans);
        if(x==-1)ans++;
        return ans;
    }
};