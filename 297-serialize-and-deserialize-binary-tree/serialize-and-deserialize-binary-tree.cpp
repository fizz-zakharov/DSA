/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)return "";
        string s=to_string(root->val);
        s.push_back(',');
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left!=NULL){
                s+=to_string(node->left->val);
                s.push_back(',');
                q.push(node->left);
            }
            else{
                s.push_back('.');
                s.push_back(',');
            }
            if(node->right!=NULL){
                s+=to_string(node->right->val);
                s.push_back(',');
                q.push(node->right);
            }
            else{
                s.push_back('.');
                s.push_back(',');
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        int i=0;
        while(data[i]!=',')i++;
        int value=stoi(data.substr(0,i));
        TreeNode* root=new TreeNode(value);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            int c=0;
            while(i<data.size()){
                if(data[i]==','){
                    i++;
                    continue;
                }
                if(data[i]=='.'){
                    if(c==0){
                        node->left=NULL;
                        c++;
                        i++;
                        continue;
                    }
                    else{
                        node->right=NULL;
                        i++;
                        break;
                    }
                }
                int j=i;
                while(data[j]!=','){
                    j++;
                }
                int temp=stoi(data.substr(i,j-i));
                TreeNode* next=new TreeNode(temp);
                if(c==0){
                    node->left=next;
                    c++;
                    q.push(next);
                    i=j+1;
                    continue;
                }
                else{
                    node->right=next;
                    q.push(next);
                    i=j+1;
                    break;
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));