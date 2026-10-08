class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        string ans;
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                c++;
                if(c!=1)ans.push_back(s[i]);
            }
            else{
                c--;
                if(c!=0)ans.push_back(s[i]);
            }
        }
        return ans;
    }
};