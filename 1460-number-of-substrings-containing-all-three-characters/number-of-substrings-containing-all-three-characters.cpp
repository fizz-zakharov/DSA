class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int> m={-1,-1,-1};
        int ans=0;
        for(int i=0;i<n;i++){
            m[s[i]-'a']=i;
            if(m[0]!=-1 && m[1]!=-1 && m[2]!=-1){
                ans+=min({m[0],m[1],m[2]})+1;
            }
        }
        return ans;
    }
};