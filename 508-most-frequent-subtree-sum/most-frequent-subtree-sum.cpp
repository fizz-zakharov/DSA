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
    int fn(TreeNode* node,map<int,int>& m){
        if(!node)return 0;
        if(node->left==NULL && node->right==NULL){
            m[node->val]++;
            return node->val;
        }
        int a=0,b=0;
        if(node->left!=NULL){
            a+=fn(node->left,m);
        }
        if(node->right!=NULL){
            b+=fn(node->right,m);
        }
        m[a+b+node->val]++;
        return a+b+node->val;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int> m;
        if(root->left==NULL && root->right==NULL)return {root->val};
        int x=fn(root,m);
        int maxfreq=INT_MIN;
        for(auto it:m)maxfreq=max(maxfreq,it.second);
        vector<int> ans;
        for(auto it:m){
            if(it.second==maxfreq)ans.push_back(it.first);
        }
        return ans;
    }
};