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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,pair<int,int>> m;
        vector<int> parent(1e5+1,-1);
        int rt;
        for(auto it:descriptions){
            int u=it[0];
            int l=-1;
            int r=-1;
            int k=it[1];
            int flag=it[2];
            if(flag){
                l=k;
            }
            else{
                r=k;
            }
            if(m.find(u)!=m.end()){
                if(flag){
                    m[u].first=k;
                }
                else{
                    m[u].second=k;
                }
            }
            else{
                m[u]={l,r};
            }
            parent[k]=u;
            if(parent[u]==-1)parent[u]=0;
        }
        for(int i=1;i<parent.size();i++){
            if(parent[i]==0){
                rt=i;
                break;
            }
        }
        TreeNode* root=new TreeNode(rt);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(m.find(node->val)!=m.end()){
                if(m[node->val].first!=-1){
                    TreeNode* l=new TreeNode(m[node->val].first);
                    node->left=l;
                    q.push(node->left);
                }
                if(m[node->val].second!=-1){
                    TreeNode* r=new TreeNode(m[node->val].second);
                    node->right=r;
                    q.push(node->right);
                }
            }
        }
        return root;

    }
};