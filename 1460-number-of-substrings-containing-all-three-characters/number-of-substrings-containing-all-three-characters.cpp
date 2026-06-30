class Solution {
private:
    int f(string s,int k){
        int n=s.size();
        unordered_map<char,int> m;
        int j=0,ans=0;
        int sz=0;
        for(int i=0;i<n;i++){
            m[s[i]]++;
            sz=m.size();
            if(sz<=k){
                ans+=i-j+1;
                continue;
            }
            while(sz>k){
                m[s[j]]--;
                if(m[s[j]]==0)m.erase(s[j]);
                j++;
                sz=m.size();
            }
            ans+=i-j+1;
        }
        return ans;
    }
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        return f(s,3)-f(s,2);
    }
};