class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> m;
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++){
            m[s[i]]++;
            while(m[s[i]]>2){
                m[s[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};