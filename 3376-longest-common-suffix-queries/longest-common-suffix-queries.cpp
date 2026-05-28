const int MAXNODES = 5000000;

struct TrieNode{
    int len;
    int ind;
    int children[26];
    bool end;
};

TrieNode pool[MAXNODES];
int poolIdx=0;

int newNode(){
    pool[poolIdx].len=INT_MAX;
    pool[poolIdx].ind=INT_MAX;
    pool[poolIdx].end=false;
    for(int i=0;i<26;i++)pool[poolIdx].children[i]=-1;
    return poolIdx++;
}

class Trie{
public:
    int root;
    Trie(){
        poolIdx=0;
        root=newNode();
    }

    void insert(string& s,int idx){
        int node=root;
        int n=s.size();
        for(int i=0;i<=n;i++){
            if((int)s.size()<pool[node].len||((int)s.size()==pool[node].len&&idx<pool[node].ind)){
                pool[node].len=s.size();
                pool[node].ind=idx;
            }
            if(i==n){
                pool[node].end=true;
                break;
            }
            int c=s[i]-'a';
            if(pool[node].children[c]==-1)pool[node].children[c]=newNode();
            node=pool[node].children[c];
        }
    }

    int getind(string& s){
        int node=root;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(pool[node].children[s[i]-'a']==-1)return pool[node].ind;
            node=pool[node].children[s[i]-'a'];
        }
        return pool[node].ind;
    }
};


class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie t;
        for(int i=0;i<(int)wordsContainer.size();i++){
            string rev = wordsContainer[i];
            reverse(rev.begin(),rev.end());
            t.insert(rev,i);
        }

        vector<int> ans;
        for(auto& it:wordsQuery){
            string rev=it;
            reverse(rev.begin(),rev.end());
            ans.push_back(t.getind(rev));
        }
        return ans;
    }
};