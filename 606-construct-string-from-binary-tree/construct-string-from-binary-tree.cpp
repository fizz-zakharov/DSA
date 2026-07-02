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
    void preorder(TreeNode* node,string& s){
        if(!node)return;
        
        s+=(to_string(node->val));
        if(node->left!=NULL){
            s.push_back('(');
            preorder(node->left,s);
            s.push_back(')');
        }
        else if(node->right!=NULL){
            s.push_back('(');
            s.push_back(')');
        }
        if(node->right!=NULL){
            s.push_back('(');
            preorder(node->right,s);
            s.push_back(')');
        }
    }
public:
    string tree2str(TreeNode* root) {
        string ans;
        preorder(root,ans);
        return ans;
    }
};