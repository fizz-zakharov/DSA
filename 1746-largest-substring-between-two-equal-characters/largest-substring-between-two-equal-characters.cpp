class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.size();
        unordered_map<char,int> m;
        for(int i=n-1;i>=0;i--){
            if(m.find(s[i])==m.end()){
                m[s[i]]=i;
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(m[s[i]]!=i){
                ans=max(ans,m[s[i]]-i-1);
            }
        }
        return ans;
    }
};