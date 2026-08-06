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
    int low=0,high=0;
    void trav(TreeNode* node,vector<int>& inorder,bool ch){
        if(!node)return;
        trav(node->left,inorder,ch);
        if(ch){
            if(node->val==high)node->val=low;
            else if(node->val==low)node->val=high;
        }
        inorder.push_back(node->val);
        trav(node->right,inorder,ch);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        trav(root,inorder,false);
        int n=inorder.size();
        vector<int> temp=inorder;
        sort(temp.begin(),temp.end());
        bool ch=true;
        for(int i=0;i<n;i++){
            if(inorder[i]!=temp[i]){
                if(ch){
                    low=temp[i];
                    ch=false;
                }
                else{
                    high=temp[i];
                }
            }
        }
        trav(root,inorder,true);

    }
};