class Solution {
map<string,char> m;
vector<string> ans;
int dp[31][31];
bool fn(int i,string& s,int k,int c){
    if(i>=k)return c>=2;
    string temp=s.substr(i,k-i);
    if(m[temp]>0)return dp[i][c]= true;
    if(dp[i][c] !=-1)return dp[i][c];
    for(int l=1;l<=k-i;l++){
        string st=s.substr(i,l);
        bool ch=false;
        if(m[st]>0)ch=true;
        if(ch&&fn(i+l,s,k,c+1)){
            return dp[i][c]= true;
        }
    }
    return dp[i][c]= false;
}
public:
    static bool cmp(string &a,string &b){
        return a.size()<b.size();
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),cmp);
        for(int i=0;i<n;i++){
            memset(dp,-1,sizeof(dp));
            if(fn(0,words[i],words[i].size(),0))ans.push_back(words[i]);
            m[words[i]]++;
        }
        return ans;

    }
};