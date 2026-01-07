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
public:
    int maxLevelSum(TreeNode* root) {
        
        queue<pair<TreeNode*,int>> q;
        vector<long long> v(1e5,0);
        q.push({root,1});
        int maxlevel=1;
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int level= q.front().second;
            q.pop();
            maxlevel = max(maxlevel, level);
            v[level]+=node->val;
            if(node->left!=NULL){
                q.push({node->left,level+1});
            }
            if(node->right!=NULL){
                q.push({node->right,level+1});
            }
        }
        int ans=0,cur=INT_MIN;
        for(int i=1;i<=maxlevel;i++){
            if(v[i]>cur){
                cur=v[i];
                ans=i;
            }
        }
        return ans;
    }
};