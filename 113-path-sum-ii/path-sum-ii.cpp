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
    void dfs(TreeNode* node,vector<vector<int>>& ans,vector<int>& temp,int sum,int target){
        if(!node)return;
        if(node!=NULL && node->left==NULL && node->right==NULL){
            if(sum+node->val==target){
                temp.push_back(node->val);
                ans.push_back(temp);
                temp.pop_back();
            }
            return;
        }
        temp.push_back(node->val);
        dfs(node->left,ans,temp,sum+node->val,target);
        dfs(node->right,ans,temp,sum+node->val,target);
        temp.pop_back();
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(root,ans,temp,0,targetSum);
        return ans;
    }
};