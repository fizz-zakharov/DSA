class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        int i=0,j=0;
        int c=0;
        while(i<n && j<m){
            if(s[i]==t[j]){
                c++;
                i++;
            }
            j++;
        }
        if(c==n)return true;
        return false;
    }
};