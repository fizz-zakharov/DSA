class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.size();
        vector<int> freq(33,-2);
        int mask=0;
        unordered_map<char,int> m;
        m['a']=0;
        m['e']=1;
        m['i']=2;
        m['o']=3;
        m['u']=4;
        int ans=0;
        freq[0]=-1;
        for(int i=0;i<n;i++){
            if(m.find(s[i])!=m.end()){
                mask=(mask)^(1<<m[s[i]]);
            }
            if(freq[mask]!=-2){
                ans=max(ans,i-freq[mask]);
            }
            else{
                freq[mask]=i;
            }
        }
        return ans;

    }
};