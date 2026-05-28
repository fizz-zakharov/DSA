class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char c){
        data=c;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    TrieNode* root;
    void insertutil(TrieNode* root,int i,string word){
        if(i>=word.size()){
            root->isTerminal=true;
            return;
        }
        TrieNode* node;
        if(root->children[word[i]-'a']!=NULL){
            node=root->children[word[i]-'a'];
            
        }
        else{
            node=new TrieNode(word[i]);
            root->children[word[i]-'a']=node;
        }
        insertutil(node,i+1,word);
    }



    bool ch(TrieNode* root,int i,string s){
        if(i>=s.size()){
            if(root->isTerminal)return true;
            return false;
        }
        bool ans=false;
        if(root->children[s[i]-'a']!=NULL){
            ans=ch(root->children[s[i]-'a'],i+1,s);
        }
        else ans=false;
        return ans;
    }

    bool pre(TrieNode* root,int i,string s){
        if(i>=s.size()){
            return true;
        }
        bool ans=false;
        if(root->children[s[i]-'a']!=NULL){
            ans=pre(root->children[s[i]-'a'],i+1,s);
        }
        else ans=false;
        return ans;
    }

    void insert(string word) {
        insertutil(root,0,word);
    }
    
    bool search(string word) {
        return ch(root,0,word);
    }
    
    bool startsWith(string prefix) {
        return pre(root,0,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */