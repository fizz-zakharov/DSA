class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<vector<int>> pre(n+1,vector<int>(26,0));
        unordered_map<char,int> lastocc,firstocc;
        for(int i=0;i<n;i++){
            pre[i+1][s[i]-'a']++;
            if(firstocc.find(s[i])==firstocc.end())firstocc[s[i]]=i;
            lastocc[s[i]]=i;
            for(int j=0;j<26;j++){
                pre[i+1][j]+=pre[i][j];
            }
        }
        int ans=0;
        for(auto it:firstocc){
            char c=it.first;
            int i=firstocc[c];
            int last=lastocc[c];
            if(last-i>1){
                for(int j=0;j<26;j++){
                    int rem=pre[last][j]-pre[i+1][j];
                    if(rem>0)ans++;
                }
            }
            
        }
        return ans;

    }
};