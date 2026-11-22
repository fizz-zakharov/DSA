class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        bool ch=false;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                ch=true;
            }
            if(ch && s[i]=='a')return false;
        }
        return true;
    }
};