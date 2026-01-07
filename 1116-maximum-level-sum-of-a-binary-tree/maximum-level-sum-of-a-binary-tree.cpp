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

        if (root == NULL) return 0;  

        queue<pair<TreeNode*,int>> q;
        vector<long long> v(1e5, 0); 

        q.push({root, 1});
        int maxLevel = 1;

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            v[level] += node->val;   
            maxLevel = max(maxLevel, level);

            if(node->left != NULL){
                q.push({node->left, level + 1});
            }
            if(node->right != NULL){
                q.push({node->right, level + 1});
            }
        }

        int ans = 1;
        long long cur = LLONG_MIN;

        for(int i = 1; i <= maxLevel; i++){   
            if(v[i] > cur){
                cur = v[i];
                ans = i;
            }
        }
        return ans;
    }
};
